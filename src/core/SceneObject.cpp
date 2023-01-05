//
//  SceneObject.cpp
//  Labirint
//
//  Created by marina porkhunova on 20.12.2022.
//

#include "SceneObject.hpp"


uint SceneObject::GetSettings()
{
    return _settings;
    
};

pair<int,int> SceneObject::GetPosition()
{
    return _position;
}

void SceneObject::SetPosition(int x, int y)
{
    _position.first = x;
    _position.second = y;
}
