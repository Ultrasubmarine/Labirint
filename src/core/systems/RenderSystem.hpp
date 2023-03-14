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

//TODO LAYERS
class RenderSystem
{
    SDL_Renderer *_render;
    
public:
    RenderSystem(SDL_Window *window);
    ~RenderSystem();
        
    void Render();
    void Present();
    
    SDL_Renderer* GetRenderer();
};


#endif /* Render_hpp */
