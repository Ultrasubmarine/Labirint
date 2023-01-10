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
concept InheritorSceneObject = std::is_base_of_v<SceneObject, T>;

template<InheritorSceneObject T>
T* CreateSceneObject(uint SCENE_OBJ_SETTINGS)
{
    // for C++ < C++20
    //static_assert(std::is_base_of_v<SceneObject, T>, "Template class isn't inherited from SceneObject");
    T* tmp = new T(SCENE_OBJ_SETTINGS);

    SceneObject* scnO = dynamic_cast<SceneObject*>(tmp);
    Game::Instance().scene->OnCreateObject(scnO); // doesnt work

    if(SCENE_OBJ_SETTINGS & SCENE_OBJ_RENDER)
        Game::Instance().renderSystem->AddRenderObj(scnO);
    return tmp;
};

void DeleteSceneObject(SceneObject* obj);

#endif /* CoreFunctions_hpp */
