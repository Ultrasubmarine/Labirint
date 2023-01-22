//
//  GameObjectHUB.hpp
//  Labirint
//
//  Created by marina porkhunova on 19.01.2023.
//

#ifndef GameObjectHUB_hpp
#define GameObjectHUB_hpp

#include <stdio.h>

#include "Component.hpp"

#include <map>
#include <typeindex>

struct GameObjectHUB
{
public:
    
    GameObjectHUB(sid id);
    const sid _id;
    std::map<std::type_index, Component*> components;
};

#endif /* GameObjectHUB_hpp */
