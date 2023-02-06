//
//  GameObjectHUB.cpp
//  Labirint
//
//  Created by marina porkhunova on 19.01.2023.
//

#include "GameHub.hpp"

GameHub::GameHub(SId id): _id(id)
{
    
};

SId GameHub::GetSid()
{
    return _id;
}

bool GameHub::HasComponent(TypeId component_id)
{
    if(_components.find(component_id) != _components.end() )
        return true;
    return false;
}

Component* GameHub::GetComponent(TypeId component_id)
{
    if(auto it =_components.find(component_id); it!= _components.end() )
    {
        return it->second;
    }
    return nullptr;
}

const std::map<TypeId, Component*>& GameHub::GetAllComponents()
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
