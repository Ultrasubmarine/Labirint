//
//  DebugSystem.hpp
//  Labirint
//
//  Created by marina porkhunova on 06.03.2023.
//

#ifndef DebugSystem_hpp
#define DebugSystem_hpp

#include <stdio.h>

#include <SDL2/SDL.h>
#include "TextTexture.hpp"



class DebugSystem
{
    std::string fontName = "Roboto-Light";
    
    SDL_Rect *dst;
    int last_fps;
    std::shared_ptr<TextTexture> fpsText;
    
public:
    DebugSystem(){
        dst = new SDL_Rect();
        dst->x = 5;
        dst->y = 5;
    };
    
    void Update();
    void Render(SDL_Renderer* renderer);
    void Log(std::string str);
};

#endif /* DebugSystem_hpp */
