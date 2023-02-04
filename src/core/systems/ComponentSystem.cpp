//
//  ComponentSystem.cpp
//  Labirint
//
//  Created by marina porkhunova on 22.01.2023.
//

#include "ComponentSystem.hpp"
#include "ComponentFactory.hpp"


map<type_index, map<sid,Component*>> ComponentSystem::_allComponents = {};

bool ComponentSystem::IsComponentExist(type_index componentID, sid objectID)
{
    if(auto it = _allComponents.find(componentID); it != _allComponents.end())
    {
        if(it->second.find(objectID) != it->second.end())
             return true;
    }
    return false;
}

Component* ComponentSystem::CreateComponent(type_index componentID, sid objectID)
{
    if(IsComponentExist(componentID, objectID))
        return nullptr;
  
    Component *c = ComponentFactory::Create(componentID, objectID);
    _allComponents[componentID][objectID] = c;
    return c;
}

void ComponentSystem::DeleteComponent(type_index componentID, sid objectID)
{
    if(auto it = _allComponents.find(componentID); it != _allComponents.end())
    {
        if(auto obj = it->second.find(objectID); obj != it->second.end())
        {
            it->second.erase(obj);
            delete obj->second;
        }
    }
}

Component* ComponentSystem::GetComponentBySid(type_index componentID, sid objectID)
{
    if(auto it = _allComponents.find(componentID); it != _allComponents.end())
    {
        if(auto it_c = it->second.find(objectID); it_c != it->second.end())
            return it_c->second;
    }
    return nullptr;
}


#include "MovingScript.hpp"
void ComponentSystem::UpdateComponents()
{
    for( auto c : _allComponents[type_index(typeid(MovingScript))])
    {
        (static_cast<Script*>(c.second))->Update();
      //  (static_cast<Script>(c))->Update();
    }
}
