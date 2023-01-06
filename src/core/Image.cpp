//
//  Image.cpp
//  Labirint
//
//  Created by marina porkhunova on 06.01.2023.
//

#include "Image.hpp"

Image::Image(SDL_Texture *texture, SDL_Rect *srcrect)
{
    SetImage(texture, srcrect);
}

Image::~Image()
{
    if(this->texture)
        SDL_DestroyTexture(texture);
}

void Image::SetImage(SDL_Texture *texture, SDL_Rect* srcrect)
{
    //TODO Create special texture loader (load, delete texture)
    if(this->texture)
        SDL_DestroyTexture(texture);
    
    this->texture = texture;
    if(srcrect)
    {
        this->srcrect.x = srcrect->x;
        this->srcrect.y = srcrect->y;
        this->srcrect.w = srcrect->w;
        this->srcrect.h = srcrect->h;
        
        return;
    }
    
    SDL_QueryTexture(texture, NULL, NULL, &this->srcrect.w , &this->srcrect.h);
    
    this->srcrect.x = 0;
    this->srcrect.y = 0;
}
