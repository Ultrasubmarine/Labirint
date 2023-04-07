//
//  FrameRate.hpp
//  Labirint
//
//  Created by marina porkhunova on 07.03.2023.
//

#ifndef FrameRate_hpp
#define FrameRate_hpp

#include <stdio.h>
#include <chrono>

#define DEFAULT_FPS 60

class FrameRate
{
    bool fixedFrameRate = false;
    
    std::chrono::nanoseconds delta;
    std::chrono::nanoseconds fixedDelta;
    
    std::chrono::time_point<std::chrono::steady_clock> last_clock, now_clock;
    
public:
     
    void FirstInitialization();
    void SetFixedFrame(int fps);
    void WaitFrame();
    
    float GetDeltaTime(); /// in milliseconds
    float GetFixedDeltaTime();
    
};
#endif /* FrameRate_hpp */
