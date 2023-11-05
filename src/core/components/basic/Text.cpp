//
//  Text.cpp
//  Labirint
//
//  Created by marina porkhunova on 25.02.2023.
//

#include "Text.hpp"

COMPONENT_CPP(Text)


#include "Game.hpp"
#include "CoreFunctions.hpp"

void Text::Init()
{
    transform = GetComponent<Transform>(_sid);
    dst = new SDL_Rect();
    
    dst->x = transform->GetPosition().x;
    dst->y = transform->GetPosition().y;
}

void Text::SetTexture(std::shared_ptr<TextTexture> texture, SDL_Rect* srcrect)
{
    _texture = texture;
    _dirty = true;
}

SDL_Texture* Text::GetTexture()
{
    return _texture->texture;
}

const SDL_Rect& Text::GetRect()
{
    return _texture->rect;
}

bool Text::IsDirty()
{
    return _dirty;
}

void Text::ClearDirty()
{
    _dirty = false;
}

#include "Game.hpp"

void Text::Serialize(json &j)
{
}

void Text::Deserialize(json &j)
{
    auto font = j["font"].get<std::string>();
    auto text = j["text"].get<std::string>();
    auto size = j["size"].get<int>();
    auto color = j["color"].get<std::vector<Uint8>>();
    if(!text.empty() && !font.empty())
    {
        auto txt =  Game::Instance().resourceManager->GetTextTexture(text, font, size, SDL_Color{ color[0], color[1], color[2]});
        SetTexture(txt);
    }
}


void Text::Draw(SDL_Renderer* render)
{
    if(transform->IsDirty() || IsDirty())
    {
        auto p = transform->GetPosition();

        dst->x = p.x;
        dst->y = p.y;
        dst->w = _texture->rect.w * transform->GetScale().x;
        dst->h = _texture->rect.h * transform->GetScale().y;
        
        transform->ClearDirty();
        ClearDirty();
    }
    
    SDL_RenderCopy(render, _texture->texture, &_texture->rect, dst);
}
