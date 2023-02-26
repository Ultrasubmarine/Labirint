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


#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>




struct TextTexture
{
    std::string text;
    SDL_Texture *texture;
    std::shared_ptr<TTF_Font> font;
    SDL_Color color;
    
    ~TextTexture()
    {
        SDL_DestroyTexture(texture);
    }
};

#endif /* TextTexture_hpp */
