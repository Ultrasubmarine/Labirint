//
//  ComponentSystem.hpp
//  Labirint
//
//  Created by marina porkhunova on 22.01.2023.
//

#ifndef ComponentSystem_hpp
#define ComponentSystem_hpp

#include <stdio.h>
#include <map>
#include <list>
#include <string>
#include <typeinfo>
#include <typeindex>


#include "StringID.hpp"
#include "Component.hpp"
#include "Script.hpp"
//#include "Game.hpp"

using namespace std;


class ComponentSystem
{
public:
    static map<type_index, map<sid,Component*>> _allComponents;
    
    static list<type_index> _updateableComponents;
    
//    static Component* CreateComponent(type_index typeID, sid ObjectID);
    
   static void AddComponent(type_index typeID, sid ObjectID, Component* c);
    
    static void DeleteComponent(type_index typeID, sid objectID);
    static void DeleteComponent(Component* c, sid objectID);
    
    static Component* GetComponentBySid(type_index typeID, sid objectID);
    
};



////template<typename T>
void DeleteComponent(type_index typeID, sid objectID);



#endif /* ComponentSystem_hpp */
