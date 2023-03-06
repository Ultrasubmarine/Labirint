//
//  TextureLoader.hpp
//  Labirint
//
//  Created by marina porkhunova on 07.01.2023.
//

#ifndef TextureLoader_hpp
#define TextureLoader_hpp

#include <memory>
#include <string>
#include <stdio.h>
#include <unordered_map>

#include <SDL2/SDL.h>

#include "Texture.hpp"

class TextureLoader
{
    SDL_Renderer *_render;

    std::unordered_map<std::string, std::weak_ptr<Texture>> _textures;

public:
    TextureLoader(SDL_Renderer *render);
    ~TextureLoader();
    
    std::shared_ptr<Texture> GetTexture(std::string& name);
    std::shared_ptr<Texture> LoadTexture(std::string& name, char *fullPath);
};

#endif /* TextureLoader_hpp */
