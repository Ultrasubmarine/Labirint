//
//  Render.cpp
//  Labirint
//
//  Created by marina porkhunova on 06.01.2023.
//

#include "Game.hpp"
#include "RenderSystem.hpp"
#include "Transform.hpp"

RenderSystem::RenderSystem(SDL_Window *window)
{
    _render = SDL_CreateRenderer(window, -1,
                                 SDL_RENDERER_ACCELERATED); //| SDL_RENDERER_TARGETTEXTURE);    
}

void RenderSystem::Render()
{
    SDL_SetRenderDrawColor(_render, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(_render);
    
    for(auto obj : _objects)
    {
        auto image = obj.first->GetImage();
        if(!image)
            continue;
            
        if(obj.first->GetTransform().IsDirty() || image->IsDirty())
        {
            auto t = obj.first->GetTransform();
            auto p = t.GetPosition();

            obj.second.x = p.x;
            obj.second.y = p.y;
            obj.second.w = image->GetRect().w * t.GetScale().x;
            obj.second.h = image->GetRect().h * t.GetScale().y;
            
            t.ClearDirty();
            image->ClearDirty();
        }

        SDL_RenderCopy(_render, image->GetTexture(), &image->GetRect(), &obj.second);
    }
    
    SDL_RenderPresent(_render);
}

void RenderSystem::AddRenderObj(GameObject *obj)
{
    Transform &t = obj->GetTransform();
    
    SDL_Rect dst;
    
    dst.x = t.GetPosition().x;
    dst.y = t.GetPosition().y;

    auto image = obj->GetImage();
    if(image)
    {
        dst.w = image->GetRect().w * t.GetScale().x;
        dst.y = image->GetRect().h * t.GetScale().y;
    }

    _objects[obj] = dst;    
}

void RenderSystem::AddRenderObj(sid id, Image* image)
{
    RenderObject obj;
    obj.transform = GetComponent<Transform>(id);
    obj.image = image;
    
    _renderObjects[id] = obj;
}

void RenderSystem::DeleteRenderObj(GameObject *obj)
{
    _objects.erase(obj);
}

void RenderSystem::DeleteRenderObj(sid id)
{
    _renderObjects.erase(id);
}

SDL_Renderer* RenderSystem::GetRenderer()
{
    return _render;
}

RenderSystem::~RenderSystem()
{
    SDL_DestroyRenderer(_render);
}
