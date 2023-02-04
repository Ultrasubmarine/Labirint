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

public:

    static map<type_index, map<sid,Component*>> _allComponents;
    static list<type_index> _updateableComponents;
    
    static Component* CreateComponent(type_index componentID, sid objectID);
    
    static void DeleteComponent(type_index componentID, sid objectID);
    static void DeleteComponent(Component* c, sid objectID);
    
    static Component* GetComponentBySid(type_index componentID, sid objectID);
    static bool IsComponentExist(type_index componentID, sid objectID);
};


////template<typename T>
void DeleteComponent(type_index typeID, sid objectID);



#endif /* ComponentSystem_hpp */
