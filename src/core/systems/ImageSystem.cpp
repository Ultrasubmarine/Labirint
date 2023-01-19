//
//  ImageSystem.cpp
//  Labirint
//
//  Created by marina porkhunova on 19.01.2023.
//

#include "ImageSystem.hpp"
#include "Game.hpp"

Image* ImageSystem::CreateImage(sid id)
{
    if(_objects.find(id) != _objects.end())
        return nullptr;
    
    Image *i = new Image(id);
    if(i)
    {
        _objects[id] = i;
        Game::Instance().renderSystem->AddRenderObj(id, i);
    }

    return i;
};

void ImageSystem::DeleteImage(sid id)
{
    auto obj = _objects.find(id);
    
    if(obj != _objects.end())
    {
        Game::Instance().renderSystem->DeleteRenderObj(id);
        
        delete obj->second;
        _objects.erase(obj);
    }
};

ImageSystem::~ImageSystem()
{
    for(auto i: _objects)
    {
        delete i.second;
    }
    _objects.clear();
}


Image* ImageSystem::GetImageBySID(sid id)
{
    auto i = _objects.find(id);
    return i != _objects.end() ? i->second : nullptr;
}
