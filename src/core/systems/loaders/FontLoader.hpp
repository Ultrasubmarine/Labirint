//
//  FontLoader.hpp
//  Labirint
//
//  Created by marina porkhunova on 25.02.2023.
//

#ifndef FontLoader_hpp
#define FontLoader_hpp

#include <stdio.h>
#include <map>
#include <SDL2/SDL.h>

#include "Texture.hpp"

class FontLoader
{
    SDL_Renderer *_render;

    // TODO hash + unordered map & smart_ptr
    std::map<std::string, Texture*> _fonts;

public:
    FontLoader(SDL_Renderer *render);
    ~FontLoader();
    
    Texture* GetFont(std::string& name);
    Texture* LoadFont(std::string& name, char *fullPath);
};
#endif /* FontLoader_hpp */
