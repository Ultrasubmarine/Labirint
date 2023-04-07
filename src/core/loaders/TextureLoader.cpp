//
//  TextureLoader.cpp
//  Labirint
//
//  Created by marina porkhunova on 07.01.2023.
//

#include "TextureLoader.hpp"

#include <string>
#include <iostream>


TextureLoader::TextureLoader(SDL_Renderer *render)
{
    _render = render;
}

void TextureLoader::DeleteTexture(Texture* texture)
{
    _textures.erase(texture->name);
    delete texture;
}

std::shared_ptr<Texture> TextureLoader::GetTexture(std::string& name)
{
    if(auto it = _textures.find(name); it != _textures.end())
        return it->second.lock() ;
    
    return nullptr;
}

std::shared_ptr<Texture> TextureLoader::LoadTexture(std::string& name, char *fullPath)
{
    SDL_Surface *bmpSurf = SDL_LoadBMP(fullPath);
    
    SDL_Texture *bmpTex = SDL_CreateTextureFromSurface(_render, bmpSurf);
    
    SDL_Rect src;
    src.x = 0;
    src.y = 0;
    src.w = bmpSurf->w;
    src.h = bmpSurf->h;
    SDL_FreeSurface(bmpSurf);
    
    if(bmpTex)
    {
        std::shared_ptr<Texture> texture{new Texture{ name, bmpTex, src}, [this](Texture* t){ this->DeleteTexture(t);}};
        
        _textures[name] = std::weak_ptr<Texture>{texture};
        return texture;
    }
    
    std::cout<<"error: TextureLoader::LoadTexture() texture:"<<name;
    return NULL;
}


TextureLoader::~TextureLoader()
{
    _textures.clear();
}

