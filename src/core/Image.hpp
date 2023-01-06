//
//  Image.hpp
//  Labirint
//
//  Created by marina porkhunova on 06.01.2023.
//

#ifndef Image_hpp
#define Image_hpp

#include <stdio.h>
#include <SDL2/SDL.h>


class Image
{
private:
    SDL_Texture *texture;
    SDL_Rect srcrect;
    
public:
    
    Image(SDL_Texture *texture, SDL_Rect* srcrect = NULL);
    ~Image();
    
    void SetImage(SDL_Texture *texture, SDL_Rect* srcrect = NULL);
};

#endif /* Image_hpp */
