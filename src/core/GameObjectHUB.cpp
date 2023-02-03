//
//  GameObjectHUB.cpp
//  Labirint
//
//  Created by marina porkhunova on 19.01.2023.
//

#include "GameObjectHUB.hpp"

GameObjectHUB::GameObjectHUB(sid id): _id(id)
{
    
};

sid GameObjectHUB::GetSid()
{
    return _id;
}

bool GameObjectHUB::HasComponent(std::type_index component_id)
{
    if(_components.find(component_id) != _components.end() )
        return true;
    return false;
}

Component* GameObjectHUB::GetComponent(std::type_index component_id)
{
    if(auto it =_components.find(component_id); it!= _components.end() )
    {
        return it->second;
    }
    return nullptr;
}

const std::map<std::type_index, Component*>& GameObjectHUB::GetAllComponents()
{
    return _components;
}

void GameObjectHUB::AddComponent(std::type_index component_id, Component* component)
{
    _components[component_id] = component;
}

void GameObjectHUB::RemoveComponent(std::type_index component_id, Component* component)
{
    _components.erase(component_id);
}
