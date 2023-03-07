//
//  DebugSystem.cpp
//  Labirint
//
//  Created by marina porkhunova on 06.03.2023.
//

#include "DebugSystem.hpp"
#include "Game.hpp"


void DebugSystem::Update()
{
    int fps = 1/Game::Instance().time.GetDeltaTime();
    
    if(  last_fps != fps)
    {
        auto s = "fps:" + std::to_string(fps);
        fpsText = Game::Instance().resourceManager->GetTextTexture(s, fontName, 14, SDL_Color{255,0,0});
        last_fps = fps;
        
        dst->w = fpsText->rect.w;
        dst->h = fpsText->rect.h;
    }
}

void DebugSystem::Draw(SDL_Renderer* render)
{
    SDL_RenderCopy(render, fpsText->texture, &fpsText->rect, dst);
}
