//
//  Rect.hpp
//  Labirint
//
//  Created by marina porkhunova on 09.07.2023.
//

#ifndef Rect_hpp
#define Rect_hpp

#include <stdio.h>
#include <SDL2/SDL.h>

#include "Texture.hpp"
#include "Component.hpp"

class Rect: public Component
{
   COMPONENT_BODY(Rect)

    int _widtht;
    int _height;
    
    SDL_Rect r;
protected:
    void Init() override;
    
public:
    void Draw(SDL_Renderer* render) override;
    
};
#endif /* Rect_hpp */
