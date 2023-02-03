//
//  CoreFunctions.hpp
//  Labirint
//
//  Created by marina porkhunova on 07.01.2023.
//

#ifndef CoreFunctions_hpp
#define CoreFunctions_hpp

#include <stdio.h>
#include <list>

#include "Game.hpp"
#include "GameObjectHUB.hpp"


GameObjectHUB* CreateGameObjectHUB(const char* uniqueName, std::list<type_index> &components);

Component* CreateComponent(type_index component_id, GameObjectHUB* hub);

void DeleteSceneObjectHUB(sid objID);


void DeleteComponent(type_index component_id, sid objectID);

//template <typename T>
//concept ScriptObject = std::is_base_of_v<Script, T>;
//
//template<ScriptObject T>
//void CreateScript()
//{
//    if( (&T::Update) != &Script::Update)
//    {
//        ComponentSystem::_updateableComponents.push_front( type_index(typeid(T)) );
//    }
//}
//
//
//template<typename T>
//T* CreateComponent(sid objectID)
//{
//    T* c = new T(objectID);
//    ComponentSystem::AddComponent(type_index(typeid(T)),objectID, c);
//    return c;
//};

template<typename T>
T* GetComponent(sid objectID)
{
    auto c = ComponentSystem::GetComponentBySid(type_index(typeid(T)),objectID);
    return static_cast<T*>(c);
};

#endif /* CoreFunctions_hpp */
