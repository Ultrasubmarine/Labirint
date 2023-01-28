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
    
   static void AddComponent(type_index typeID, sid ObjectID, Component*);
   static void DeleteComponent(type_index typeID, sid objectID);
    
   static Component* GetComponentBySid(type_index typeID, sid objectID);
    
};

template <typename T>
concept ScriptObject = std::is_base_of_v<Script, T>;

template<ScriptObject T>
void CreateScript()
{
    if( (&T::Update) != &Script::Update)
    {
        ComponentSystem::_updateableComponents.push_front( type_index(typeid(T)) );
    }
}


template<typename T>
T* CreateComponent(sid objectID)
{   
    T* c = new T(objectID);
    ComponentSystem::AddComponent(type_index(typeid(T)),objectID, c);
    return c;
};



////template<typename T>
void DeleteComponent(type_index typeID, sid objectID);

template<typename T>
T* GetComponent(sid objectID)
{
    auto c = ComponentSystem::GetComponentBySid(type_index(typeid(T)),objectID);
    return static_cast<T*>(c);
};

#endif /* ComponentSystem_hpp */
