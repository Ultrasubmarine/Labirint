//
//  TextureLoader.hpp
//  Labirint
//
//  Created by marina porkhunova on 07.01.2023.
//

#ifndef TextureLoader_hpp
#define TextureLoader_hpp

#include <stdio.h>
#include <string>
#include <map>

#include <SDL2/SDL.h>

#include "Texture.hpp"

class TextureLoader
{
    SDL_Renderer *_render;

    // TODO hash + unordered map & smart_ptr
    std::map<std::string, Texture*> _textures;

    Texture* LoadTexture(std::string& name, char *fullPath);
public:
    TextureLoader(SDL_Renderer *render);
    ~TextureLoader();
    
    Texture* GetTexture(std::string& name, char *fullPath);
};

#endif /* TextureLoader_hpp */
