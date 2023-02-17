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


GameHub* CreateGameHub(const char* uniqueName, std::list<TypeId>* components)
{
    GameHub* hub = Game::Instance().scene->CreateGameHub(uniqueName);
    
    if(hub && components)
    {
        for(auto type_id: *components)
        {
            CreateComponent(type_id,hub);
        }
    }
    return hub;
};

//TODO looking for gameHub two times; bad;
void DeleteGameHub(SId objID)
{
    auto hub = Game::Instance().scene->GetGameHub(objID);
    
    if(!hub)
        return;
    
    for(auto comp : hub->GetAllComponents())
    {
        DeleteComponent(comp.first, objID);
    }

    Game::Instance().scene->DestroyGameHub(hub);
};

Component* CreateComponent(TypeId component_id, GameHub* hub)
{
    if(hub->HasComponent(component_id))
        return nullptr;
    
    SId object_id = hub->GetSid();
    
    Component *c = ComponentSystem::CreateComponent(component_id, object_id);
    
    
    //TODO hide it somewhere 
    if(component_id == Image::GetTypeInfo().id )
    {
       auto im = static_cast<Image*>(c);
       Game::Instance().renderSystem->AddRenderObj(object_id, im);
    }
    hub->AddComponent(component_id, c);
    return c;
}

void DeleteComponent(TypeId typeID, SId objectID)
{
    ComponentSystem::DeleteComponent(typeID, objectID);
}
