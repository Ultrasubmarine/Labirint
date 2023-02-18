//
//  Window.hpp
//  Labirint
//
//  Created by marina porkhunova on 18.02.2023.
//

#ifndef Window_hpp
#define Window_hpp

#include <SDL2/SDL.h>
#include <stdio.h>

#include "json.hpp"
using json = nlohmann::json;

class Window
{
    SDL_Window* window;

public:
    Window(const json* settings);
    ~Window();
    
    SDL_Window* GetWindow();
};
#endif /* Window_hpp */
