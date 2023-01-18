//
//  CoreFunctions.hpp
//  Labirint
//
//  Created by marina porkhunova on 07.01.2023.
//

#ifndef CoreFunctions_hpp
#define CoreFunctions_hpp

#include <stdio.h>

#include "Game.hpp"

template <typename T>
concept InheritorSceneObject = std::is_base_of_v<GameObject, T>;

template<InheritorSceneObject T>
T* CreateSceneObject(const char* uniqueName, uint SCENE_OBJ_SETTINGS)
{
    //TODO check does item with this SID alreary exist

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

#endif /* CoreFunctions_hpp */
