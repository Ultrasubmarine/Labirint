//
//  ComponentFactory.hpp
//  Labirint
//
//  Created by marina porkhunova on 29.01.2023.
//

#ifndef ComponentFactory_hpp
#define ComponentFactory_hpp

#include <stdio.h>
#include <map>
#include "Component.hpp"
#include "ComponentSystem.hpp"

class ComponentFactory
{
public:
    using TCreateComponent = Component*(*)();

    static bool Register(type_index typeID, TCreateComponent createFunc);
    static Component* Create(type_index typeID);
    
private:
    static std::map<type_index, TCreateComponent> _factoryMethods;
};

#endif /* ComponentFactory_hpp */
