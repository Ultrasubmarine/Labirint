//
//  component.cpp
//  Labirint
//
//  Created by marina porkhunova on 19.01.2023.
//

#include "Component.hpp"
#include "ComponentFactory.hpp"

Component::Component(sid id)
{
    _sid = id;
}

const sid Component::GetSid()
{
    return _sid;
};


bool RegisterComponent(type_index componentID, TCreateComponent createFunc)
{
    return ComponentFactory::Register(componentID, createFunc);
}

const TypeInfo* Component::GetTypeInfo()
{
    return _typeInfo;
}
