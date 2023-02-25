//
//  FontLoader.cpp
//  Labirint
//
//  Created by marina porkhunova on 25.02.2023.
//

#include "FontLoader.hpp"
#include <iostream>

#include <SDL2_ttf/SDL_ttf.h>

FontLoader::FontLoader(SDL_Renderer *render)
{
    _render = render;
    
    if (TTF_Init()==-1) {
        printf("error FontLoader::FontLoader(): %s", SDL_GetError());
        return ;
    }
}

Texture* FontLoader::GetFont(std::string& name)
{
    if(auto it = _fonts.find(name); it != _fonts.end())
        return it->second;
    
    return nullptr;
}

Texture* FontLoader::LoadFont(std::string& name, char *fullPath)
{
    SDL_Surface *bmpSurf = SDL_LoadBMP(fullPath);
    
    SDL_Texture *bmpTex = SDL_CreateTextureFromSurface(_render, bmpSurf);
    SDL_FreeSurface(bmpSurf);
    
    if(bmpTex)
        return _fonts[name] = new Texture{ name, bmpTex};
    
    std::cout<<"error: TextureLoader::LoadTexture() texture:"<<name;
    return NULL;
}


FontLoader::~FontLoader()
{
    for(auto t : _textures)
    {
        delete t.second;
    }
    _textures.clear();
}
