//
//  ComponentSystem.cpp
//  Labirint
//
//  Created by marina porkhunova on 22.01.2023.
//

#include "ComponentSystem.hpp"
#include "Debug.h"

unordered_map<TypeId, unordered_map<SId,Component*>> ComponentSystem::_allComponents = {};

list<TypeId>& ComponentSystem::DrawList()
{
    static list<TypeId> drawComponents = {};
    return drawComponents;
}

list<TypeId>& ComponentSystem::UpdateList()
{
    static list<TypeId> updateableComponents = {};
    return updateableComponents;
}

FactoryMethod<TypeId, Component, SId>& ComponentSystem::ComponentFactory()
{
    static FactoryMethod<TypeId, Component, SId> factory = {};
    return factory;
}

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
  
    Component *c = ComponentFactory().Create(componentID, objectID);//ComponentFactory::Create(componentID, objectID);
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

const unordered_map<SId,Component*>* ComponentSystem::GetAllComponentByType(TypeId componentID)
{
    if(auto it = _allComponents.find(componentID); it != _allComponents.end())
    {
        return &it->second;
    }
    return nullptr;
}

const list<TypeId>& ComponentSystem::GetUpdateList()
{
    return UpdateList();
}

const list<TypeId>& ComponentSystem::GetDrawList()
{
    return DrawList();
}

void ComponentSystem::UpdateComponents(double deltaTime)
{
    for(auto u_id : UpdateList())
    {
        if(auto c_it = _allComponents.find(u_id); c_it != _allComponents.end())
        {
            for( auto c : c_it->second)
            {
                c.second->Update(deltaTime);
            }
        }
    }
}

void ComponentSystem::RegisterUpdateComponent(TypeId componentID)
{
    UpdateList().push_back(componentID);
}

void ComponentSystem::RegisterDrawComponent(TypeId componentID)
{
    DrawList().push_back(componentID);
}

bool ComponentSystem::RegisterComponent(const TypeInfo &typeInfo, TCreateComponent createFunc)
{
    bool b = ComponentFactory().Register(typeInfo.id, createFunc);
    
    if(b)
        LOG("ComponentSystem::RegisterComponent: " + std::string(typeInfo.name) +" (Success)");
    else
        LOG("ComponentSystem::RegisterComponent: " + std::string(typeInfo.name) + "  (Fail)");

    return b;
}
