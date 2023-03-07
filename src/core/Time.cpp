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
//    delta = std::chrono::nanoseconds;
    last_clock = std::chrono::steady_clock::now();
}

#include <iostream>

void Time::CalculateNewFrameTime()
{    
    static auto now_clock = std::chrono::high_resolution_clock::now();
  
    last_clock = now_clock;
    now_clock = std::chrono::high_resolution_clock::now();
    
    delta = std::chrono::duration_cast<std::chrono::milliseconds>(now_clock - last_clock);
    
}


double Time::GetDeltaTime()
{
    return std::chrono::duration<double>(delta).count();
}

std::chrono::nanoseconds Time::GetElapsedTime()
{
    return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - last_clock);
}
