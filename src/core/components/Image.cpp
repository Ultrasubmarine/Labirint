//
//  Image.cpp
//  Labirint
//
//  Created by marina porkhunova on 06.01.2023.
//

#include "Image.hpp"

#include "ComponentFactory.hpp"

REGISTER_COMPONENT_CPP(Image)

void Image::SetTexture(SDL_Texture *texture, SDL_Rect* srcrect)
{
    _texture = texture;
    if(srcrect)
    {
        this->_srcrect.x = srcrect->x;
        this->_srcrect.y = srcrect->y;
        this->_srcrect.w = srcrect->w;
        this->_srcrect.h = srcrect->h;
        
        return;
    }
    
    SDL_QueryTexture(texture, NULL, NULL, &this->_srcrect.w , &this->_srcrect.h);
    
    this->_srcrect.x = 0;
    this->_srcrect.y = 0;
    
    _dirty = true;
}

SDL_Texture* Image::GetTexture()
{
    return _texture;
}

const SDL_Rect& Image::GetRect()
{
    return _srcrect;
}

bool Image::IsDirty()
{
    return _dirty;
}

void Image::ClearDirty()
{
    _dirty = false;
}
