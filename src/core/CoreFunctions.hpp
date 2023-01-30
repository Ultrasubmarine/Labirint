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

void DeleteSceneObjectHUB(sid objID);

#endif /* CoreFunctions_hpp */
