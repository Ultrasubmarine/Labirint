//
//  SceneObject.cpp
//  Labirint
//
//  Created by marina porkhunova on 20.12.2022.
//

#include "GameObject.hpp"


GameObject::GameObject(sid sid,uint SCENE_OBJ_SETTINGS) : _settings{SCENE_OBJ_SETTINGS}, _image{NULL}
{
    _sid = sid;
};

GameObject::~GameObject()
{
    if(_image)
        delete _image;
}

uint GameObject::GetSettings()
{
    return _settings;
};

Transform& GameObject::GetTransform()
{
    return _transform;
}

Image* GameObject::GetImage()
{
    return _image;
}

void GameObject::SetImageTexture(SDL_Texture* texture, SDL_Rect* src)
{
    if(!_image)
        _image = new Image(texture,src);
    else
        _image->SetTexture(texture,src);
}


void GameObject::Tick(float delta_tick)
{
    
}
