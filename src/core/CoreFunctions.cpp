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


GameHub* CreateGameHub(const char* uniqueName, std::list<TypeId> &components)
{
    auto id = SID(uniqueName);
    GameHub* hub = new GameHub(id);
    Game::Instance().scene->_allHubs[id] = hub;
    
    for(auto type_id: components)
    {
        CreateComponent(type_id,hub);
    }
    return hub;
};

void DeleteGameHub(SId objID)
{
    auto obj = Game::Instance().scene->_allHubs.find(objID);
    if(obj == Game::Instance().scene->_allHubs.end())
        return;
    
    for(auto comp : obj->second->GetAllComponents())
    {
        DeleteComponent(comp.first, objID);
    }
    
    Game::Instance().scene->_allHubs.erase(obj);
    DESTROY_SID(objID);
    delete obj->second;
};

Component* CreateComponent(TypeId component_id, GameHub* hub)
{
    if(hub->HasComponent(component_id))
        return nullptr;
    
    SId object_id = hub->GetSid();
    
    Component *c = ComponentSystem::CreateComponent(component_id, object_id);
    
    
    //TODO hide it somewhere 
    if(component_id == TYPE_ID(Image) )
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
