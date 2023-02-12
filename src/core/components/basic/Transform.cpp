//
//  Transform.cpp
//  Labirint
//
//  Created by marina porkhunova on 05.01.2023.
//

#include "Transform.hpp"

COMPONENT_CPP(Transform)

const Point2D<int>& Transform::GetPosition()
{
   return this->position;
}

const Point2D<float>& Transform::GetScale()
{
   return this->scale;
}

void Transform::Offset(int x, int y)
{
    position.x += x;
    position.y += y;
    
    _dirty = true;
}

void Transform::SetPosition(int x, int y)
{
    position.x = x;
    position.y = y;
    
    _dirty = true;
}

void Transform::SetScale(float x, float y)
{
    scale.x = x;
    scale.y = y;
    
    _dirty = true;
}

bool Transform::IsDirty()
{
    return _dirty;
}

void Transform::ClearDirty()
{
    _dirty = false;
}

void Transform::Init()
{
    scale.x = 1;
    scale.y = 1;
}

void Transform::Serialize(json &j)
{
    position.x = j["position"]["x"].get<int>();
    position.y = j["position"]["y"].get<int>();
}

void Transform::Deserialize(json &j)
{
   // j << position.x 
}

