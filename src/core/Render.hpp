//
//  Render.hpp
//  Labirint
//
//  Created by marina porkhunova on 06.01.2023.
//

#ifndef Render_hpp
#define Render_hpp

#include <stdio.h>
#include <set>

#include "SceneObject.hpp"
#include <map>
#include <set>

#include <SDL2/SDL.h>


class RenderSystem
{
    SDL_Renderer *_render;
    
    std::map<SceneObject*, SDL_Rect> _objects;
    
public:
    
    RenderSystem(SDL_Window *window);
    ~RenderSystem();
    
    void AddRenderObj(SceneObject *obj);
    void DeleteRenderObj(SceneObject *obj);
    
    void Render();
    SDL_Renderer* GetRenderer();
};

#endif /* Render_hpp */
