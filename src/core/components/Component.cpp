//
//  component.cpp
//  Labirint
//
//  Created by marina porkhunova on 19.01.2023.
//

#include "Component.hpp"
#include "ComponentSystem.hpp"
#include "Debug.h"

Component::Component(SId id)
{
    _sid = id;
}

Component::~Component()
{
    LOG("Delete Component (type: " + std::string{_typeInfo->name} + " sid: " + std::to_string(_sid) + ")");
};

const SId Component::GetSid()
{
    return _sid;
};

const TypeInfo* Component::GetTypeInfo()
{
    return _typeInfo;
}


bool RegisterComponent(const char *componentName, TCreateComponent createFunc)
{
    if(componentName == nullptr)
        return false;
    
    auto ti = TypeInfoStorage::GetTypeInfoByName(componentName);
    return ComponentSystem::RegisterComponent(*ti, createFunc);
}

bool RegisterUpdate(TypeId compoenntID)
{
    ComponentSystem::RegisterUpdateComponent(compoenntID);
    return true;
}

bool RegisterDraw(TypeId compoenntID)
{
    ComponentSystem::RegisterDrawComponent(compoenntID);
    return true;
}


