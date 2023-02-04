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

#include "ComponentSystem.hpp"
#include "GameObjectHUB.hpp"


GameObjectHUB* CreateGameObjectHUB(const char* uniqueName, std::list<type_index> &components);
void DeleteSceneObjectHUB(sid objID);

Component* CreateComponent(type_index component_id, GameObjectHUB* hub);
void DeleteComponent(type_index component_id, sid objectID);

template<typename T>
T* GetComponent(sid objectID)
{
    auto c = ComponentSystem::GetComponentBySid(type_index(typeid(T)),objectID);
    return static_cast<T*>(c);
};

#endif /* CoreFunctions_hpp */
