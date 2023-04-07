//
//  Texture.hpp
//  Labirint
//
//  Created by marina porkhunova on 12.02.2023.
//

#ifndef Texture_hpp
#define Texture_hpp

#include <string>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <iostream>
struct Texture
{
    std::string name;
    
    SDL_Texture *texture;
    SDL_Rect src;
    
    ~Texture()
    {
        SDL_DestroyTexture(texture);
    }
};


#endif /* Texture_hpp */
