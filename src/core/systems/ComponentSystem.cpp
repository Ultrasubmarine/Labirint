//
//  ComponentSystem.cpp
//  Labirint
//
//  Created by marina porkhunova on 22.01.2023.
//

#include "ComponentSystem.hpp"


map<type_index, map<sid,Component*>> ComponentSystem::_allComponents = {};

void ComponentSystem::AddComponent(type_index typeID, sid objectID, Component *component)
{    
    _allComponents[typeID][objectID] = component;
}

void ComponentSystem::DeleteComponent(type_index typeID, sid objectID)
{
    
    auto c = _allComponents[typeID].find(objectID);
    if(c == _allComponents[typeID].end())
    {
        _allComponents[typeID].erase(objectID);
        delete c->second;
    } 
}

Component* ComponentSystem::GetComponentBySid(type_index typeID, sid objectID)
{
    auto c = _allComponents[typeID].find(objectID);
    if( c != _allComponents[typeID].end())
        return c->second;
    return nullptr;
}

void DeleteComponent(type_index typeID, sid objectID)
{
    ComponentSystem::DeleteComponent(typeID, objectID);
}
