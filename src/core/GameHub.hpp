//
//  GameObjectHUB.hpp
//  Labirint
//
//  Created by marina porkhunova on 19.01.2023.
//

#ifndef GameObjectHUB_hpp
#define GameObjectHUB_hpp

#include <stdio.h>
#include <map>

#include "Component.hpp"


struct GameHub
{
protected:
    std::map<TypeId, Component*> _components;
    const SId _id;
    
public:
    GameHub(SId id);
    ~GameHub();
    
    SId GetSid();
    
    bool HasComponent(TypeId component_id);
    Component* GetComponent(TypeId component_id);
    const std::map<TypeId, Component*>& GetAllComponents();
    
    void AddComponent(TypeId component_id, Component* component);
    void RemoveComponent(TypeId component_id, Component* component);
};

#endif /* GameObjectHUB_hpp */
