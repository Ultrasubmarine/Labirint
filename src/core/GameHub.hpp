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
//#include "CoreFunctions.hpp"
class Scene;

//struct GameHub;
//inline GameHub* CreateGameHub(const char* uniqueName, std::list<TypeId>* components);

enum ObjectMode
{
    SceneOnly,
    Global
};

struct GameHub
{
    using Ptr = std::shared_ptr<GameHub>;
    using WeakPtr = std::weak_ptr<GameHub>;
    
protected:
    std::map<TypeId, Component*> _components;
    const SId _id;
    
public:

    const SId GetSid() const;
    
    bool HasComponent(TypeId component_id) const;
    Component* GetComponent(TypeId component_id) const;
    const std::map<TypeId, Component*>& GetAllComponents() const;
    
    void AddComponent(TypeId component_id, Component* component);
    void RemoveComponent(TypeId component_id, Component* component);
    
private:
    GameHub(SId id);
    ~GameHub();
    
    
    // TODO only one friend function
    friend class Scene;
  //  friend inline GameHub* CreateGameHub(const char* uniqueName, std::list<TypeId>* components);
};

#endif /* GameObjectHUB_hpp */
