//
//  ComponentFactory.cpp
//  Labirint
//
//  Created by marina porkhunova on 29.01.2023.
//

#include "ComponentFactory.hpp"
#include <iostream>


std::map<TypeId, TCreateComponent>& ComponentFactory::TheMap()
{
    static map<TypeId, TCreateComponent> factoryMethods{};
    return factoryMethods;
}

bool ComponentFactory::Register(const TypeInfo &typeInfo, TCreateComponent createFunc)
{
    if(TheMap().find(typeInfo.id) != TheMap().end())
    {
        std::cout<< "register fail: "<<typeInfo.name<<endl;
        return false;
    }
    
    std::cout<< "register sucsess: "<<typeInfo.name<<endl;
    TheMap()[typeInfo.id] = createFunc;
    return true;
}

Component* ComponentFactory::Create(TypeId typeID, sid id)
{
    if(auto it = TheMap().find(typeID); it != TheMap().end())
    {
        return it->second(id);
    }
    return nullptr;
}
