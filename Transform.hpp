//
//  Transform.hpp
//  Labirint
//
//  Created by marina porkhunova on 05.01.2023.
//

#ifndef Transform_hpp
#define Transform_hpp

#include <stdio.h>
//#include "PositionPrimitives.hpp"


#endif /* Transform_hpp */

template<typename T>
struct Point2D
{
    T x;
    T y;
};


class Transform
{
    Point2D<int> position; // world
    Point2D<float> scale;
    
//    SDL_Rect srcrect;
//    SDL_Rect dstrect;
  
public:
    
    const Point2D<int>& GetPosition();
    
    void Offset(int x, int y);
    void SetPosition(int x, int y);    
};

