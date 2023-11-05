//
//  Image.cpp
//  Labirint
//
//  Created by marina porkhunova on 06.01.2023.
//

#include "Image.hpp"

COMPONENT_CPP(Image)

void Image::SetTexture(std::shared_ptr<Texture> texture, SDL_Rect* srcrect)
{
    _texture = texture;
    
 //   SDL_QueryTexture(texture->texture, NULL, NULL, &this->_srcrect.w , &this->_srcrect.h);

    
    _dirty = true;
}

SDL_Texture* Image::GetTexture()
{
    return _texture->texture;
}

const SDL_Rect& Image::GetRect()
{
    return _texture->src;
}

bool Image::IsDirty()
{
    return _dirty;
}

#include "Game.hpp"
#include "CoreFunctions.hpp"
#include <SDL2/SDL.h>

void Image::Init()
{
    transform = GetComponent<Transform>(_sid);
    //TODO FREE MEMORY
    dst = new SDL_Rect();
    
    dst->x = transform->GetPosition().x;
    dst->y = transform->GetPosition().y;
}

void Image::ClearDirty()
{
    _dirty = false;
}


void Image::Serialize(json &j)
{

}

void Image::Deserialize(json &j)
{
    auto tx_name = j["texture"].get<std::string>();
    if(!tx_name.empty())
    {
        auto txt =   Game::Instance().resourceManager->GetTexture(tx_name);
        SetTexture(txt);
    }
}


void Image::Draw(SDL_Renderer* render)
{
    if(transform->IsDirty() || IsDirty())
    {
        auto p = transform->GetPosition();

        dst->x = p.x;
        dst->y = p.y;
        dst->w = _texture->src.w * transform->GetScale().x;
        dst->h = _texture->src.h * transform->GetScale().y;
        
        transform->ClearDirty();
        ClearDirty();
    }
    
    SDL_RenderCopy(render, _texture->texture , &_texture->src, dst);
};
