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

#define GET_COMPONENT(CLASS_NAME, sid) GetComponent<CLASS_NAME>(sid, TYPE_ID(CLASS_NAME))


GameObjectHUB* CreateGameObjectHUB(const char* uniqueName, std::list<TypeId> &components);
void DeleteSceneObjectHUB(sid objID);

Component* CreateComponent(TypeId component_id, GameObjectHUB* hub);
void DeleteComponent(TypeId component_id, sid objectID);


template <typename T>
concept InheritorComponent = std::is_base_of_v<Component, T>;

template<InheritorComponent T>
T* GetComponent(sid objectID, TypeId componentID)
{
    auto c = ComponentSystem::GetComponentBySid(componentID,objectID);
    return static_cast<T*>(c);
};

#endif /* CoreFunctions_hpp */
