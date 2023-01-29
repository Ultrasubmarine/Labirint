//
//  ComponentFactory.cpp
//  Labirint
//
//  Created by marina porkhunova on 29.01.2023.
//

#include "ComponentFactory.hpp"
#include <iostream>


map<type_index, ComponentFactory::TCreateComponent> ComponentFactory::_factoryMethods;

bool ComponentFactory::Register(type_index typeID, TCreateComponent createFunc)
{
    static std::map<type_index, TCreateComponent> _factoryMethods;
    
    if(_factoryMethods.find(typeID) != _factoryMethods.end())
        return false;
   
    _factoryMethods[typeID] = createFunc;
    std::cout<< "register sucsess"<<endl;
    return true;
}

Component* ComponentFactory::Create(type_index typeID)
{
    if(auto it = _factoryMethods.find(typeID); it != _factoryMethods.end())
    {
        return it->second();
    }
    return nullptr;
}
