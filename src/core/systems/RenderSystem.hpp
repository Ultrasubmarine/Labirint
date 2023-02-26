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
//#include "Text.hpp"

//TODO refactor this system; remove image/text;
struct RenderObject
{
    Transform* transform;
    Image* image;
 //   Text* text;
    SDL_Rect* dst;
};

class RenderSystem
{
    SDL_Renderer *_render;
    
    std::map<SId, RenderObject> _renderObjects;
    
public:
    
    RenderSystem(SDL_Window *window);
    ~RenderSystem();
    
    void AddRenderObj(SId id, Image* image);
  //  void AddRenderObj(SId id, Text* image); // temp stuff for checking
    void DeleteRenderObj(SId id);
    
    void Render();
    SDL_Renderer* GetRenderer();
};


#endif /* Render_hpp */
