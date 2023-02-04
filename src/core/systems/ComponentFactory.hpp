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

using namespace std;

class ComponentFactory
{
public:
    ComponentFactory() = delete;
    
    static bool Register(type_index typeID, TCreateComponent createFunc);
    static Component* Create(type_index typeID, sid id);
    
private:
    static std::map<type_index, TCreateComponent>& TheMap();
};

#endif /* ComponentFactory_hpp */
