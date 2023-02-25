//
//  Text.hpp
//  Labirint
//
//  Created by marina porkhunova on 25.02.2023.
//

#ifndef Text_hpp
#define Text_hpp

#include <stdio.h>
#include "Component.hpp"
#include "Image.hpp"

#include <string>
#include <SDL2/SDL.h>


class Text: Image
{
    COMPONENT_BODY(Text, Image)
    
//    std::string text;
//
    SDL_Color color;
    Texture* texture;
    
//
//    // now you can convert it into a texture
//    SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
//
//    SDL_Rect Message_rect; //create a rect
//
//
public:

    void Render();    
    void SetText(std::string& text);
  
};

#endif /* Text_hpp */
