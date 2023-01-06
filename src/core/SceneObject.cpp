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

//pair<int,int> SceneObject::GetPosition()
//{
//  //  return _position;
//}

void SceneObject::SetPosition(int x, int y)
{
//    _position.first = x;
//    _position.second = y;
}


void SceneObject::SetTexture(SDL_Texture* texture)
{
    this->texture = texture;
    
    
    SDL_QueryTexture(texture, NULL, NULL, &srcrect.w , &srcrect.h);
    
    srcrect.x = 0;
    srcrect.y = 0;

    dstrect.x = 640/2;
    dstrect.y = 480/2;
    dstrect.w = srcrect.w;
    dstrect.h = srcrect.h;
}


Transform& SceneObject::GetTransform()
{
    return _transform;
}
