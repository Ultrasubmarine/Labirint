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
protected:
    std::map<std::type_index, Component*> _components;
    const sid _id;
    
public:
    GameObjectHUB(sid id);

    sid GetSid();
    
    bool HasComponent(std::type_index component_id);
    Component* GetComponent(std::type_index component_id);
    const std::map<std::type_index, Component*>& GetAllComponents();
    
    void AddComponent(std::type_index component_id, Component* component);
    void RemoveComponent(std::type_index component_id, Component* component);
};

#endif /* GameObjectHUB_hpp */
