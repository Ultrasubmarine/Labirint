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
#include <list>

#include "Component.hpp"
class Scene;

struct GameHub final
{
    using Ptr = std::shared_ptr<GameHub>;
    using WeakPtr = std::weak_ptr<GameHub>;
    
protected:
    std::map<TypeId, Component*> _components;
    const SId _id;
    
public:

    const SId GetSid() const { return _id; };
    
    bool HasComponent(TypeId component_id) const;
    Component* GetComponent(TypeId component_id) const;
    const std::map<TypeId, Component*>& GetAllComponents() const;
    
    void AddComponent(TypeId component_id, Component* component);
    void RemoveComponent(TypeId component_id, Component* component); 
   
private:
    ~GameHub();
    GameHub(SId id);
    
    friend class Scene;
};


//void Bub() {};
#endif /* GameObjectHUB_hpp */
