//
//  DebugSystem.cpp
//  Labirint
//
//  Created by marina porkhunova on 06.03.2023.
//

#include "DebugSystem.hpp"
#include "Game.hpp"


DebugSystem::DebugSystem()
{
}

DebugSystem::~DebugSystem()
{
}

void DebugSystem::Update()
{
    int fps = 1/Game::Instance().frameRate.GetDeltaTime();
    
    if( fpsInfo.last_fps != fps)
    {
        auto s = "fps:" + std::to_string(fps);
        auto fontName = std::string(DEFAULT_FONT);
        fpsInfo.text = Game::Instance().resourceManager->GetTextTexture(s, fontName, 14, SDL_Color{255,0,0});
        fpsInfo.last_fps = fps;
        
        fpsInfo.dst->w = fpsInfo.text->rect.w;
        fpsInfo.dst->h = fpsInfo.text->rect.h;
    }
}

void DebugSystem::Render(SDL_Renderer* render)
{
    SDL_RenderCopy(render, fpsInfo.text->texture, &fpsInfo.text->rect, fpsInfo.dst);
}

void DebugSystem::Log(std::string str , LogType log)
{
    if(log == LogType::error)
        std::cout<<"ERROR: "<<str<<std::endl;
    else
        std::cout<<str<<std::endl;
}


DebugFPS::DebugFPS()
{
    dst = new SDL_Rect();
    dst->x = 5;
    dst->y = 5;
}

DebugFPS::~DebugFPS()
{
    delete dst;
}
