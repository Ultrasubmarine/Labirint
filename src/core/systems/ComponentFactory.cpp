//
//  ComponentFactory.cpp
//  Labirint
//
//  Created by marina porkhunova on 29.01.2023.
//

#include "ComponentFactory.hpp"
#include <iostream>


std::map<type_index, TCreateComponent>& ComponentFactory::TheMap()
{
    static map<type_index, TCreateComponent> factoryMethods{};
    return factoryMethods;
}

bool ComponentFactory::Register(type_index typeID, TCreateComponent createFunc)
{
    if(TheMap().find(typeID) != TheMap().end())
    {
        std::cout<< "register fail: "<<typeID.name()<<endl;
        return false;
    }
    
    std::cout<< "register sucsess: "<<typeID.name()<<endl;
    TheMap()[typeID] = createFunc;
    return true;
}

Component* ComponentFactory::Create(type_index typeID, sid id)
{
    if(auto it = TheMap().find(typeID); it != TheMap().end())
    {
        return it->second(id);
    }
    return nullptr;
}
