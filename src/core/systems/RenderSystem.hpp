//
//  Render.hpp
//  Labirint
//
//  Created by marina porkhunova on 06.01.2023.
//

#ifndef Render_hpp
#define Render_hpp

#include <SDL2/SDL.h>
#include <stdio.h>
#include <map>

#include "Transform.hpp"
#include "Image.hpp"


struct RenderObject
{
    Transform* transform;
    Image* image;
    SDL_Rect* dst;
};

class RenderSystem
{
    SDL_Renderer *_render;
    
    std::map<sid, RenderObject> _renderObjects;
    
public:
    
    RenderSystem(SDL_Window *window);
    ~RenderSystem();
    
    void AddRenderObj(sid id, Image* image);
    void DeleteRenderObj(sid id);
    
    void Render();
    SDL_Renderer* GetRenderer();
};



#endif /* Render_hpp */
