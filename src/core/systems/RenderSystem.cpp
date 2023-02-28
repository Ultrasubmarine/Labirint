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
    SDL_SetRenderDrawColor(_render, 0,0,0,0xFF);//0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(_render);
    
    for(auto obj : _renderObjects)
    {
        if(obj.second.image)
        {
            obj.second.image->Draw(_render);
        }
        else{ // text
            if(obj.second.transform->IsDirty() || obj.second.text->IsDirty())
            {
                auto p = obj.second.transform->GetPosition();

                obj.second.dst->x = p.x;
                obj.second.dst->y = p.y;
                obj.second.dst->w = obj.second.text->GetRect().w * obj.second.transform->GetScale().x;
                obj.second.dst->h = obj.second.text->GetRect().h * obj.second.transform->GetScale().y;
                
                obj.second.transform->ClearDirty();
                obj.second.text->ClearDirty();
            }
            
            SDL_RenderCopy(_render, obj.second.text->GetTexture(), NULL, obj.second.dst);
        }
        
    }
    
    SDL_RenderPresent(_render);
}

void RenderSystem::AddRenderObj(SId id, Image* image)
{
    RenderObject obj;
//    obj.transform = GetComponent<Transform>(id);
    obj.image = image;
//    obj.dst = new SDL_Rect();
    
//    obj.dst->x = obj.transform->GetPosition().x;
//    obj.dst->y = obj.transform->GetPosition().y;
//
//    obj.dst->w = image->GetRect().w * obj.transform->GetScale().x;
//    obj.dst->y = image->GetRect().h * obj.transform->GetScale().y;
    
    _renderObjects[id] = obj;
}

void RenderSystem::AddRenderObj(SId id, Text* text)
{
    RenderObject obj;
    obj.transform = GetComponent<Transform>(id);
    obj.text = text;
    obj.dst = new SDL_Rect();
    
    obj.dst->x = obj.transform->GetPosition().x;
    obj.dst->y = obj.transform->GetPosition().y;
    
    obj.dst->w = text->GetRect().w * obj.transform->GetScale().x;
    obj.dst->y = text->GetRect().h * obj.transform->GetScale().y;
    
    _renderObjects[id] = obj;
}

void RenderSystem::DeleteRenderObj(SId id)
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
