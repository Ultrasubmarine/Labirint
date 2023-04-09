//
//  Window.cpp
//  Labirint
//
//  Created by marina porkhunova on 18.02.2023.
//

#include "Window.hpp"
#include "Debug.h"


Window::~Window()
{
    SDL_DestroyWindow(window);
    SDL_Quit();
}

Window::Window(const json* settings)
{
    if( SDL_Init(SDL_INIT_EVERYTHING ^ SDL_INIT_AUDIO))
    {
        LOG_ERROR("Window::Window() -> SDL_Init()");
        return ;
    }
    
    const char* title;
    int width, height;
    
    if(settings)
    {
        title = (*settings)["name"].get<std::string>().c_str();
        width =(*settings)["screen"]["width"].get<int>();
        height =(*settings)["screen"]["height"].get<int>();
    }
    
    window = SDL_CreateWindow(title,
                     SDL_WINDOWPOS_UNDEFINED,
                     SDL_WINDOWPOS_UNDEFINED,
                     width, height,
                     SDL_WINDOW_RESIZABLE);
    
    if(!window)
        LOG_ERROR("fail creating window");

    return;
}

SDL_Window* Window::GetWindow()
{
    return window;
}
