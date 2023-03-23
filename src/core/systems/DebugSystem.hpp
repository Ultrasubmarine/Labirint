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

struct DebugFPS
{
    int last_fps;
    std::shared_ptr<TextTexture> text;
    SDL_Rect *dst;
    
    DebugFPS();
    ~DebugFPS();
};


class DebugSystem
{
    DebugFPS fpsInfo;
    
public:
    DebugSystem();
    ~DebugSystem();
    
    void Update();
    void Render(SDL_Renderer* renderer);
    void Log(std::string str);
};

#endif /* DebugSystem_hpp */
