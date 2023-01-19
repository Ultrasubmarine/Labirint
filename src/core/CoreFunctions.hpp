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
#include "AllComponents.h"
#include "GameObjectHUB.hpp"
#include "ComponentFactory.hpp"

template <typename T>
concept InheritorSceneObject = std::is_base_of_v<GameObject, T>;

template<InheritorSceneObject T>
T* CreateSceneObject(const char* uniqueName, uint SCENE_OBJ_SETTINGS)
{
    //TODO check does item with this SID already exist

    // for C++ < C++20
    //static_assert(std::is_base_of_v<SceneObject, T>, "Template class isn't inherited from SceneObject");
    //sid f;
    T* tmp = new T(SID(uniqueName), SCENE_OBJ_SETTINGS);

    Game::Instance().scene->OnCreateObject(tmp);

    if(SCENE_OBJ_SETTINGS & SCENE_OBJ_RENDER)
        Game::Instance().renderSystem->AddRenderObj(tmp);
    return tmp;
};

void DeleteSceneObject(GameObject* obj);


GameObjectHUB* CreateGameObjectHUB(const char* uniqueName, std::list<ComponentType> &components)
{

    auto id = SID(uniqueName);
    GameObjectHUB* hub = new GameObjectHUB();
    
    Component* c;
    for(auto comp_type: components)
    {
        c = CreateComponent(id, comp_type);
        hub->components[comp_type] = c;
    }
    
    return hub;
};

#endif /* CoreFunctions_hpp */
