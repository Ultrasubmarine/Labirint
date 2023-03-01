//
//  Render.cpp
//  Labirint
//
//  Created by marina porkhunova on 06.01.2023.
//

#include "RenderSystem.hpp"
#include "ComponentSystem.hpp"

RenderSystem::RenderSystem(SDL_Window *window)
{
    _render = SDL_CreateRenderer(window, -1,
                                 SDL_RENDERER_ACCELERATED); //| SDL_RENDERER_TARGETTEXTURE);    
}

void RenderSystem::Render()
{
    SDL_SetRenderDrawColor(_render, 0,0,0,0xFF);//0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(_render);
    
    auto drawComponents = ComponentSystem::GetDrawList();
    for(auto compID: drawComponents)
    {
        auto compList = ComponentSystem::GetAllComponentByType(compID);
        for(auto c: *compList)
            c.second->Draw(_render);
    }
    SDL_RenderPresent(_render);
}


SDL_Renderer* RenderSystem::GetRenderer()
{
    return _render;
}

RenderSystem::~RenderSystem()
{
    SDL_DestroyRenderer(_render);
}
