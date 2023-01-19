//
//  GameObjectHUB.hpp
//  Labirint
//
//  Created by marina porkhunova on 19.01.2023.
//

#ifndef GameObjectHUB_hpp
#define GameObjectHUB_hpp

#include <stdio.h>

#include "AllComponents.h"
#include "Component.hpp"

#include <map>


struct GameObjectHUB
{
    std::map<ComponentType, Component*> components;
};

#endif /* GameObjectHUB_hpp */
