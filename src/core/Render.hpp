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
#include <SDL2/SDL.h>

struct RenderObj
{
    SceneObject* sceneObj;
    SDL_Rect dstrect;
};

class RenderSystem
{
    SDL_Renderer *render;
    
   
public:
    void AddRenderObj(SceneObject *obj);
    void DeleteRenderObj(SceneObject *obj);
    
    void Render(std::set<RenderObj*> renderObjects);
};

#endif /* Render_hpp */
