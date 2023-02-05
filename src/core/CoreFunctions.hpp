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


GameObjectHUB* CreateGameObjectHUB(const char* uniqueName, std::list<TypeId> &components);
void DeleteSceneObjectHUB(sid objID);

Component* CreateComponent(TypeId component_id, GameObjectHUB* hub);
void DeleteComponent(TypeId component_id, sid objectID);

template<typename T>
T* GetComponent(sid objectID)
{
    auto id = TYPE_ID(T);
    auto c = ComponentSystem::GetComponentBySid(id,objectID);
    return static_cast<T*>(c);
};

template<typename T>
T* GetComponent2(sid objectID, TypeId componentID)
{
   
    auto c = ComponentSystem::GetComponentBySid(componentID,objectID);
    return static_cast<T*>(c);
};

#endif /* CoreFunctions_hpp */
