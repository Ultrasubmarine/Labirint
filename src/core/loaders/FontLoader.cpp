//
//  FontLoader.cpp
//  Labirint
//
//  Created by marina porkhunova on 25.02.2023.
//

#include "FontLoader.hpp"
#include <iostream>

FontLoader::FontLoader(SDL_Renderer *render)
{
    _render = render;
    
    if (TTF_Init()==-1) {
        printf("error FontLoader::FontLoader(): %s", SDL_GetError());
        return ;
    }
}

void FontLoader::DeleteFont(Font* font)
{
    _fonts.erase(font->name);
    delete font;
}

std::shared_ptr<Font> FontLoader::GetFont(std::string& name)
{
    if(auto it = _fonts.find(name); it != _fonts.end())
        return it->second.lock();
    
    return nullptr;
}

std::shared_ptr<Font> FontLoader::LoadFont(std::string& name, char *fullPath)
{
    auto f =TTF_OpenFont(fullPath, 24);
    std::shared_ptr<Font> font{new Font{name,f}, [this](Font *f){ this->DeleteFont(f);} };
    
    if(font)
    {
        _fonts[name] = std::weak_ptr<Font>{font};
        return font;
    }
    
    return nullptr;
}


std::shared_ptr<TextTexture> FontLoader::GetText(std::string& text, std::shared_ptr<Font> font, int fsize, SDL_Color color)
{
    if( TTF_SetFontSize( font.get()->font, fsize) == -1)
    {
        std::cout<<"error: FontLoader::GetText() set size. \ntext:"""<<text<<""" \nsize:"<<fsize<<"\n";
    }
    
    SDL_Surface* surfaceText = TTF_RenderText_Solid(font.get()->font, text.c_str(), color);
    SDL_Texture* textTex = SDL_CreateTextureFromSurface(_render, surfaceText);
    
    SDL_Rect rect;
    rect.x = 0;
    rect.y = 0;
    rect.w = surfaceText->w;
    rect.h = surfaceText->h;
    SDL_FreeSurface(surfaceText);

    if(textTex)
        return std::shared_ptr<TextTexture>( new TextTexture{ textTex, font, text, color, rect});
    
    std::cout<<"error: FontLoader::GetText() text:"<<text;
    return NULL;
}

FontLoader::~FontLoader()
{
}


