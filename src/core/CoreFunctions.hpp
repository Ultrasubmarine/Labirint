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

//tmp
void InitGame(Game* g);

SceneObject* CreateSceneObject(uint SCENE_OBJ_SETTINGS);
void DeleteSceneObject(SceneObject* obj);

#endif /* CoreFunctions_hpp */
