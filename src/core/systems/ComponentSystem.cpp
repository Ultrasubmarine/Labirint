//
//  ComponentSystem.cpp
//  Labirint
//
//  Created by marina porkhunova on 22.01.2023.
//

#include "ComponentSystem.hpp"
#include "ComponentFactory.hpp"


map<TypeId, map<SId,Component*>> ComponentSystem::_allComponents = {};

bool ComponentSystem::IsComponentExist(TypeId componentID, SId objectID)
{
    if(auto it = _allComponents.find(componentID); it != _allComponents.end())
    {
        if(it->second.find(objectID) != it->second.end())
             return true;
    }
    return false;
}

Component* ComponentSystem::CreateComponent(TypeId componentID, SId objectID)
{
    if(IsComponentExist(componentID, objectID))
        return nullptr;
  
    Component *c = ComponentFactory::Create(componentID, objectID);
    _allComponents[componentID][objectID] = c;
    return c;
}

void ComponentSystem::DeleteComponent(TypeId componentID, SId objectID)
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

Component* ComponentSystem::GetComponentBySid(TypeId componentID, SId objectID)
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
    for( auto c : _allComponents[TYPE_ID(MovingScript)])
    {
        (static_cast<Script*>(c.second))->Update();
    }
}
