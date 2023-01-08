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

static Game* game;

//tmp
void InitGame(Game* g);


SceneObject* CreateSceneObject(uint SCENE_OBJ_SETTINGS);
void DeleteSceneObject(SceneObject* obj);

SceneObject* CreateSceneFrog(uint SCENE_OBJ_SETTINGS);

//template<class T>
//T* CreateSceneObjectT(uint SCENE_OBJ_SETTINGS)
//{
//    T* tmp = new T(SCENE_OBJ_SETTINGS);
//
//    SceneObject* scnO = dynamic_cast<SceneObject*>(tmp);
//    AddToGameCore(scnO);
//    return tmp;
//};

#endif /* CoreFunctions_hpp */
