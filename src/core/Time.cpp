//
//  Time.cpp
//  Labirint
//
//  Created by marina porkhunova on 24.02.2023.
//

#include "Time.hpp"
#include <SDL2/SDL.h>


void Time::FirstInitialization()
{
    deltaTime = 0;
}

#include <iostream>

void Time::CalculateTime()
{
    static  Uint64 _nowCounter = SDL_GetPerformanceCounter();
    static  Uint64 _lastCounter = 0;
    
    _lastCounter = _nowCounter;
    _nowCounter = SDL_GetPerformanceCounter();

    deltaTime = ((_nowCounter - _lastCounter) / static_cast<double>(SDL_GetPerformanceFrequency()));
    
 //   std::cout<< deltaTime<<std::endl;
}
