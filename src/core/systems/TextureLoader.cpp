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

Texture* TextureLoader::GetTexture(std::string& title)
{
    if(auto it = _textures.find(title); it != _textures.end())
        return it->second;
    
    return LoadTexture(title);
}

Texture* TextureLoader::LoadTexture(std::string& title)
{
    std::string r_path ="resources/images/";
    r_path.append(title);
    std::string type = "bmp";

    char *image_path = GetPath(r_path, type);
    SDL_Surface *bmpSurf = SDL_LoadBMP(image_path);
    free(image_path);
    
    SDL_Texture *bmpTex = SDL_CreateTextureFromSurface(_render, bmpSurf);
    SDL_FreeSurface(bmpSurf);
    
    if(bmpTex)
        return _textures[title] = new Texture{ title, bmpTex};
    
    std::cout<<"error: TextureLoader::LoadTexture() texture:"<<title;
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

