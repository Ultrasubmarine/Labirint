//
//  FrameRate.cpp
//  Labirint
//
//  Created by marina porkhunova on 07.03.2023.
//

#include "FrameRate.hpp"

#include <thread>


void FrameRate::FirstInitialization()
{
    delta = std::chrono::nanoseconds::zero();
    now_clock = std::chrono::steady_clock::now();
    
    fixedDelta = std::chrono::seconds(1);
    fixedDelta /= DEFAULT_FPS;
}

void FrameRate::SetFixedFrame(int fps)
{
    fixedFrameRate = true;
    
    fixedDelta = std::chrono::seconds(1);
    fixedDelta /= fps;
}


void FrameRate::WaitFrame()
{
    last_clock = now_clock;
    now_clock = std::chrono::steady_clock::now();
    
    delta = now_clock - last_clock;
    
        
    if(fixedFrameRate)
    {
        auto wait = fixedDelta - delta;
        delta += wait;
        
        if(wait > std::chrono::nanoseconds::zero())
        {
            std::this_thread::sleep_for(wait);
        }
    }
  
    last_clock = std::chrono::steady_clock::now();
}


float FrameRate::GetDeltaTime()
{
    return delta.count()/ static_cast<float>(std::nano::den);
}


float FrameRate::GetFixedDeltaTime()
{
    return fixedDelta.count()/ static_cast<float>(std::nano::den);
}
