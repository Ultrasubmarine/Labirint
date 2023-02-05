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


GameObjectHUB* CreateGameObjectHUB(const char* uniqueName, std::list<TypeId> &components)
{
    auto id = SID(uniqueName);
    GameObjectHUB* hub = new GameObjectHUB(id);
    Game::Instance().scene->_allObjHubs[id] = hub;
    
    for(auto type_id: components)
    {
        CreateComponent(type_id,hub);
    }
    return hub;
};

void DeleteSceneObjectHUB(sid objID)
{
    auto obj = Game::Instance().scene->_allObjHubs.find(objID);
    if(obj == Game::Instance().scene->_allObjHubs.end())
        return;
    
    for(auto comp : obj->second->GetAllComponents())
    {
        DeleteComponent(comp.first, objID);
    }
    
    Game::Instance().scene->_allObjHubs.erase(obj);
    delete obj->second;
};

Component* CreateComponent(TypeId component_id, GameObjectHUB* hub)
{
    if(hub->HasComponent(component_id))
        return nullptr;
    
    sid object_id = hub->GetSid();
    
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

void DeleteComponent(TypeId typeID, sid objectID)
{
    ComponentSystem::DeleteComponent(typeID, objectID);
}
