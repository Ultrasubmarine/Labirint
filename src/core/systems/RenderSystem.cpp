//
//  Render.cpp
//  Labirint
//
//  Created by marina porkhunova on 06.01.2023.
//

#include "Game.hpp"
#include "RenderSystem.hpp"
#include "Transform.hpp"

#include "CoreFunctions.hpp"
RenderSystem::RenderSystem(SDL_Window *window)
{
    _render = SDL_CreateRenderer(window, -1,
                                 SDL_RENDERER_ACCELERATED); //| SDL_RENDERER_TARGETTEXTURE);    
}

void RenderSystem::Render()
{
    SDL_SetRenderDrawColor(_render, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(_render);
    
    for(auto obj : _renderObjects)
    {
        if(obj.second.transform->IsDirty() || obj.second.image->IsDirty())
        {
            auto p = obj.second.transform->GetPosition();

            obj.second.dst->x = p.x;
            obj.second.dst->y = p.y;
            obj.second.dst->w = obj.second.image->GetRect().w * obj.second.transform->GetScale().x;
            obj.second.dst->h = obj.second.image->GetRect().h * obj.second.transform->GetScale().y;
            
            obj.second.transform->ClearDirty();
            obj.second.image->ClearDirty();
        }
        
        SDL_RenderCopy(_render, obj.second.image->GetTexture(), &obj.second.image->GetRect(), obj.second.dst);
    }
    
    SDL_RenderPresent(_render);
}

void RenderSystem::AddRenderObj(sid id, Image* image)
{
    RenderObject obj;
    obj.transform = GetComponent2<Transform>(id, TYPE_ID(Transform));
    obj.image = image;
    obj.dst = new SDL_Rect();
    
    obj.dst->x = obj.transform->GetPosition().x;
    obj.dst->y = obj.transform->GetPosition().y;
    
    obj.dst->w = image->GetRect().w * obj.transform->GetScale().x;
    obj.dst->y = image->GetRect().h * obj.transform->GetScale().y;
    
    _renderObjects[id] = obj;
}

void RenderSystem::DeleteRenderObj(sid id)
{
    auto o = _renderObjects.find(id);
    
    if(o == _renderObjects.end())
        return;
    
    _renderObjects.erase(id);
    delete o->second.dst;
}

SDL_Renderer* RenderSystem::GetRenderer()
{
    return _render;
}

RenderSystem::~RenderSystem()
{
    SDL_DestroyRenderer(_render);
}
