//
//  Text.cpp
//  Labirint
//
//  Created by marina porkhunova on 25.02.2023.
//

#include "Text.hpp"

//COMPONENT_CPP(Text)
//
//void Text::SetTexture(std::shared_ptr<TextTexture> texture, SDL_Rect* srcrect)
//{
//    _texture = texture;
//    if(srcrect)
//    {
//        this->_srcrect.x = srcrect->x;
//        this->_srcrect.y = srcrect->y;
//        this->_srcrect.w = srcrect->w;
//        this->_srcrect.h = srcrect->h;
//        
//        return;
//    }
//    
//    SDL_QueryTexture(texture->texture, NULL, NULL, &this->_srcrect.w , &this->_srcrect.h);
//    
//    this->_srcrect.x = 0;
//    this->_srcrect.y = 0;
//    
//    _dirty = true;
//}
//
//SDL_Texture* Text::GetTexture()
//{
//    return _texture->texture;
//}
//
//const SDL_Rect& Text::GetRect()
//{
//    return _srcrect;
//}
//
//bool Text::IsDirty()
//{
//    return _dirty;
//}
//
//void Text::ClearDirty()
//{
//    _dirty = false;
//}
//
//#include "Game.hpp"
//
//void Text::Serialize(json &j)
//{
//    auto font = j["font"].get<std::string>();
//    auto text = j["text"].get<std::string>();
//    auto size = j["size"].get<int>();
//    
//    if(!text.empty() && !font.empty())
//    {
//   //     auto txt =  Game::Instance().resourceManager->GetTextTexture(text, font, size);
//     //   SetTexture(txt);
//    }
//}
