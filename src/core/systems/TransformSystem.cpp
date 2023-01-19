//
//  TransformSystem.cpp
//  Labirint
//
//  Created by marina porkhunova on 19.01.2023.
//

#include "TransformSystem.hpp"


Transform* TransformSystem::CreateTransform(sid id)
{
    if(_objects.find(id) != _objects.end())
        return nullptr;
    
    Transform *t = new Transform(id);
    if(t)
        _objects[id] = t;
    return t;
};

void TransformSystem::DeleteTransform(sid id)
{
    auto obj = _objects.find(id);
    
    if(obj != _objects.end())
    {
        delete obj->second;
        _objects.erase(obj);
    }
};

TransformSystem::~TransformSystem()
{
    for(auto t: _objects)
    {
        delete t.second;
    }
    _objects.clear();
}


Transform* TransformSystem::GetTransformBySID(sid id)
{
    auto t = _objects.find(id);
    return t != _objects.end() ? t->second : nullptr;
}
