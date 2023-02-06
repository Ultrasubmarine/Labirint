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
#include "GameHub.hpp"

#define GET_COMPONENT(CLASS_NAME, sid) GetComponent<CLASS_NAME>(sid, TYPE_ID(CLASS_NAME))


GameHub* CreateGameHub(const char* uniqueName, std::list<TypeId> &components);
void DeleteGameHub(SId objID);

Component* CreateComponent(TypeId component_id, GameHub* hub);
void DeleteComponent(TypeId component_id, SId objectID);


template <typename T>
concept InheritorComponent = std::is_base_of_v<Component, T>;

template<InheritorComponent T>
T* GetComponent(SId objectID, TypeId componentID)
{
    auto c = ComponentSystem::GetComponentBySid(componentID,objectID);
    return static_cast<T*>(c);
};

#endif /* CoreFunctions_hpp */
