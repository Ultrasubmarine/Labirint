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

std::shared_ptr<TTF_Font> FontLoader::GetFont(std::string& name)
{
    if(auto it = _fonts.find(name); it != _fonts.end())
        return it->second.lock();
    
    return nullptr;
}

std::shared_ptr<TTF_Font> FontLoader::LoadFont(std::string& name, char *fullPath)
{
    auto f =TTF_OpenFont(fullPath, 24);
    std::shared_ptr<TTF_Font> font{f, [](TTF_Font* f){  TTF_CloseFont(f); } };
    
    if(font)
    {
        _fonts[name] = std::weak_ptr<TTF_Font>{font};
        return font;
    }
    
    return nullptr;
}


std::shared_ptr<TextTexture> FontLoader::GetText(std::string& text, std::shared_ptr<TTF_Font> font, int fsize)
{
    if( TTF_SetFontSize(font.get(), fsize) == -1)
    {
        std::cout<<"FontLoader::GetText error set size. \ntext:"""<<text<<""" \nsize:"<<fsize;
    }
    
    SDL_Color textColor = { 255, 0, 0, 255};
    SDL_Surface* surfaceText = TTF_RenderText_Solid(font.get(), text.c_str(), textColor);

    SDL_Texture* textTex = SDL_CreateTextureFromSurface(_render, surfaceText);
    
    auto text_width = surfaceText->w;
    auto text_height = surfaceText->h;

    SDL_FreeSurface(surfaceText);

    if(textTex)
        return std::make_shared<TextTexture>( TextTexture{ text, textTex, font});
    
    std::cout<<"error: FontLoader::GetText() text:"<<text;
    return NULL;
}

FontLoader::~FontLoader()
{
}

