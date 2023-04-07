//
//  TextTexture.hpp
//  Labirint
//
//  Created by marina porkhunova on 26.02.2023.
//

#ifndef TextTexture_hpp
#define TextTexture_hpp

#include <stdio.h>
#include <string>

#include "Font.h"
#include <SDL2/SDL.h>


struct TextTexture
{
    SDL_Texture *texture;
    
    std::shared_ptr<Font> font;
    std::string text;
    SDL_Color color;
    SDL_Rect rect;

    ~TextTexture()
    {
        SDL_DestroyTexture(texture);
    }
};

#endif /* TextTexture_hpp */
