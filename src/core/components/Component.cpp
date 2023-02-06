//
//  component.cpp
//  Labirint
//
//  Created by marina porkhunova on 19.01.2023.
//

#include "Component.hpp"
#include "ComponentFactory.hpp"

Component::Component(SId id)
{
    _sid = id;
}

const SId Component::GetSid()
{
    return _sid;
};


bool RegisterComponent(const char *componentName, TCreateComponent createFunc)
{
    if(componentName == nullptr)
        return false;
    
    auto ti = TypeInfoStorage::GetTypeInfo(componentName);
    return ComponentFactory::Register( *ti, createFunc);
}

const TypeInfo* Component::GetTypeInfo()
{
    return _typeInfo;
}
