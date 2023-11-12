//
//  CoreFunctions.cpp
//  Labirint
//
//  Created by marina porkhunova on 07.01.2023.
//

#include "CoreFunctions.hpp"
#include "Game.hpp"
#include <iostream>
#include <map>


class GameHub;

GameHub* CreateGameHub(const char* uniqueName, std::list<TypeId>* components)
{
    auto hub = Game::Instance().sceneManager->GetCurrentScene()->CreateGameHub(uniqueName);
    
    if(hub.lock().get() && components)
    {
        for(auto type_id: *components)
        {
            CreateComponent(type_id, hub.lock().get());
        }
    }
    return hub.lock().get();
};

//TODO looking for gameHub two times; bad;
void DeleteGameHub(SId objID)
{
    auto hub = Game::Instance().sceneManager->GetCurrentScene()->GetGameHub(objID);
    
    if(!hub)
        return;
    
    for(auto comp : hub->GetAllComponents())
    {
        DeleteComponent(comp.first, objID);
    }
    Game::Instance().sceneManager->GetCurrentScene()->DeleteGameHub(hub);
};

Component* CreateComponent(TypeId component_id, GameHub* hub)
{
    if(hub->HasComponent(component_id))
        return nullptr;
    
    SId object_id = hub->GetSid();

    Component *c = ComponentSystem::CreateComponent(component_id, object_id);
    hub->AddComponent(component_id, c);
    return c;
}

void DeleteComponent(TypeId typeID, SId objectID)
{
    ComponentSystem::DeleteComponent(typeID, objectID);
}
