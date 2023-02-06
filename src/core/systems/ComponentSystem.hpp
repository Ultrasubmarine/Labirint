//
//  ComponentSystem.hpp
//  Labirint
//
//  Created by marina porkhunova on 22.01.2023.
//

#ifndef ComponentSystem_hpp
#define ComponentSystem_hpp

#include <stdio.h>
#include <list>
#include <map>

#include "Component.hpp"

using namespace std;

class ComponentSystem
{
    static map<TypeId, map<SId,Component*>> _allComponents;
    static list<TypeId> _updateableComponents;
    
public:
    static Component* CreateComponent(TypeId componentID, SId objectID);
    static void DeleteComponent(TypeId componentID, SId objectID);
    
    static Component* GetComponentBySid(TypeId componentID, SId objectID);
    static bool IsComponentExist(TypeId componentID, SId objectID);
    
    static void UpdateComponents();
};

#endif /* ComponentSystem_hpp */
