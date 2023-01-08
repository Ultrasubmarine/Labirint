//
//  SceneObject.cpp
//  Labirint
//
//  Created by marina porkhunova on 20.12.2022.
//

#include "SceneObject.hpp"


SceneObject::SceneObject(uint SCENE_OBJ_SETTINGS) : _settings{SCENE_OBJ_SETTINGS}, _image{NULL}
{
};

SceneObject::~SceneObject()
{
    if(_image)
        delete _image;
}

uint SceneObject::GetSettings()
{
    return _settings;
};

Transform& SceneObject::GetTransform()
{
    return _transform;
}

Image* SceneObject::GetImage()
{
    return _image;
}

void SceneObject::SetImageTexture(SDL_Texture* texture, SDL_Rect* src)
{
    if(!_image)
        _image = new Image(texture,src);
    else
        _image->SetTexture(texture,src);
}


void SceneObject::Tick(float delta_tick)
{
    
}
