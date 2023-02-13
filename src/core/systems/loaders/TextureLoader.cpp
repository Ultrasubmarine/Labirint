//
//  TextureLoader.cpp
//  Labirint
//
//  Created by marina porkhunova on 07.01.2023.
//

#include "TextureLoader.hpp"

#include "GetPath_Apple.hpp"

#include <string>
#include <iostream>


TextureLoader::TextureLoader(SDL_Renderer *render)
{
    _render = render;
}

Texture* TextureLoader::GetTexture(std::string& name)
{
    if(auto it = _textures.find(name); it != _textures.end())
        return it->second;
    
    return nullptr;
}

Texture* TextureLoader::LoadTexture(std::string& name, char *fullPath)
{
    SDL_Surface *bmpSurf = SDL_LoadBMP(fullPath);
    
    SDL_Texture *bmpTex = SDL_CreateTextureFromSurface(_render, bmpSurf);
    SDL_FreeSurface(bmpSurf);
    
    if(bmpTex)
        return _textures[name] = new Texture{ name, bmpTex};
    
    std::cout<<"error: TextureLoader::LoadTexture() texture:"<<name;
    return NULL;
}


TextureLoader::~TextureLoader()
{
    for(auto t : _textures)
    {
        delete t.second;
    }
    _textures.clear();
}

