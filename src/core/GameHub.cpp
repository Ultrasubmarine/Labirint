//
//  GameObjectHUB.cpp
//  Labirint
//
//  Created by marina porkhunova on 19.01.2023.
//

#include "GameHub.hpp"
#include "Debug.h"

GameHub::GameHub(SId id): _id(id)
{
    LOG("Create GameObject (sid: " + std::to_string(_id) + ")");
};

GameHub::~GameHub()
{
    LOG("Delete GameObject (sid: " + std::to_string(_id) + ")");
};

const SId GameHub::GetSid() const
{
    return _id;
}

bool GameHub::HasComponent(TypeId component_id) const
{
    if(_components.find(component_id) != _components.end() )
    {
        return true;
    }
    return false;
}

Component* GameHub::GetComponent(TypeId component_id) const
{
    if(auto it =_components.find(component_id); it!= _components.end() )
    {
        return it->second;
    }
    return nullptr;
}

const std::map<TypeId, Component*>& GameHub::GetAllComponents() const
{
    return _components;
}

void GameHub::AddComponent(TypeId component_id, Component* component)
{
    _components[component_id] = component;
}

void GameHub::RemoveComponent(TypeId component_id, Component* component)
{
    _components.erase(component_id);
}
