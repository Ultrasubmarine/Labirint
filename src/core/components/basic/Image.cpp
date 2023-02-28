//
//  Image.cpp
//  Labirint
//
//  Created by marina porkhunova on 06.01.2023.
//

#include "Image.hpp"

COMPONENT_CPP(Image)

void Image::SetTexture(Texture *texture, SDL_Rect* srcrect)
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
    
    SDL_QueryTexture(texture->texture, NULL, NULL, &this->_srcrect.w , &this->_srcrect.h);
    
    this->_srcrect.x = 0;
    this->_srcrect.y = 0;
    
    _dirty = true;
}

SDL_Texture* Image::GetTexture()
{
    return _texture->texture;
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

#include "Game.hpp"

void Image::Serialize(json &j)
{
    auto tx_name = j["texture"].get<std::string>();
    if(!tx_name.empty())
    {
        auto txt =   Game::Instance().resourceManager->GetTexture(tx_name);
        SetTexture(txt);
    }
}

void Image::Deserialize(json &j)
{
   // j << position.x
}

void Image::Draw()
{
    //Image::
     std::cout<<"image draw";
};
