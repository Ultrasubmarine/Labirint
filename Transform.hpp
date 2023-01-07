//
//  Transform.hpp
//  Labirint
//
//  Created by marina porkhunova on 05.01.2023.
//

#ifndef Transform_hpp
#define Transform_hpp

#include <stdio.h>
#include "PositionPrimitives.hpp"

//template<typename T>
//struct Point2D
//{
//    T x;
//    T y;
//};
class Transform
{
    Point2D<int> position; // world
    Point2D<float> scale;

    bool _dirty;
public:
    
    Transform();
    const Point2D<int>& GetPosition();
    const Point2D<float>& GetScale();
    
    void Offset(int x, int y);
    void SetPosition(int x, int y);
    void SetScale(float x, float y);
    
    bool IsDirty();
    void ClearDirty();
};

#endif /* Transform_hpp */




