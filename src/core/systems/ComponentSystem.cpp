//
//  ComponentSystem.cpp
//  Labirint
//
//  Created by marina porkhunova on 22.01.2023.
//

#include "ComponentSystem.hpp"


map<TypeId, map<SId,Component*>> ComponentSystem::_allComponents = {};
list<TypeId> ComponentSystem::_updateableComponents = {};
FactoryMethod<TypeId, Component, SId> ComponentSystem::_factory{};

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
  
    
    Component *c = _factory.Create(componentID, objectID);//ComponentFactory::Create(componentID, objectID);
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

void ComponentSystem::RegisterUpdateComponent(TypeId componentID)
{
    _updateableComponents.push_back(componentID);
}

void ComponentSystem::UpdateComponents()
{
    for(auto u_id : _updateableComponents)
    {
        if(auto c_it = _allComponents.find(u_id); c_it != _allComponents.end())
        {
            for( auto c : c_it->second)
            {
                c.second->Update();
            }
        }
    }
}

bool ComponentSystem::RegisterComponent(const TypeInfo &typeInfo, TCreateComponent createFunc)
{
    bool b = _factory.Register(typeInfo.id, createFunc);
    
    std::cout<<"ComponentSystem::RegisterComponent: "<<typeInfo.name;
    if(b)
        std::cout<<" (Success)"<<endl;
    else
        std::cout<<" (Fail)"<<endl;

    return b;
}
