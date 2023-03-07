//
//  Time.hpp
//  Labirint
//
//  Created by marina porkhunova on 24.02.2023.
//

#ifndef Time_hpp
#define Time_hpp

#include <stdio.h>
#include <chrono>

class Time
{
    std::chrono::milliseconds delta;
    std::chrono::time_point<std::chrono::steady_clock> last_clock;

public:

    void FirstInitialization();
    void CalculateNewFrameTime();
    
   // Uint32 GetNowTick();
   // Uint32 GetElapsed(); //vetween start tick and now;
    
    double GetDeltaTime();

    std::chrono::nanoseconds GetElapsedTime(); // in current frame;
    
};
#endif /* Time_hpp */
