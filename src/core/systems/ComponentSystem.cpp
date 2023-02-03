//
//  ComponentSystem.cpp
//  Labirint
//
//  Created by marina porkhunova on 22.01.2023.
//

#include "ComponentSystem.hpp"
#include "ComponentFactory.hpp"


map<type_index, map<sid,Component*>> ComponentSystem::_allComponents = {};

//Component* ComponentSystem::CreateComponent(type_index typeID, sid ObjectID)
//{
//    Component *c = ComponentFactory::Create(component_id, object_id);
//    ComponentSystem::AddComponent(component_id ,object_id, c);
//    return nullptr;
//}

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


