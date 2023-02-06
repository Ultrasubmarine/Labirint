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
    
    static bool Register(const TypeInfo &typeInfo, TCreateComponent createFunc);
    static Component* Create(TypeId typeID, SId id);
    
private:
    static std::map<TypeId, TCreateComponent>& TheMap();
};

#endif /* ComponentFactory_hpp */
