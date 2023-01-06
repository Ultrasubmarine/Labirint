//
//  Transform.cpp
//  Labirint
//
//  Created by marina porkhunova on 05.01.2023.
//

#include "Transform.hpp"


const Point2D<int>& Transform::GetLocalPosition()
{
   return this->position;

};

void Transform::Offset(int x, int y)
{
    position.x += x;
    position.y += y;
};


void Transform::SetPosition(int x, int y)
{
    position.x = x;
    position.y = y;
};
