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

#include "ComponentFactory.hpp"


GameObjectHUB* CreateGameObjectHUB(const char* uniqueName, std::list<type_index> &components)
{
    auto id = SID(uniqueName);
    GameObjectHUB* hub = new GameObjectHUB(id);
    
    Component* c;
    for(auto type_id: components)
    {
       
        c = ComponentFactory::Create(type_id, id);
        ComponentSystem::AddComponent(type_id ,id, c);
        
       if(type_id == type_index(typeid(Image)) )
       {
           auto im = static_cast<Image*>(c);
           Game::Instance().renderSystem->AddRenderObj(id, im);
       }
        
        hub->components[type_id] = c;      
    }
    
    Game::Instance().scene->_allObjHubs[id] = hub;
    return hub;
};


void DeleteSceneObjectHUB(sid objID)
{
    auto obj = Game::Instance().scene->_allObjHubs.find(objID);
    
    if(obj == Game::Instance().scene->_allObjHubs.end())
        return;
    
    for(auto comp : obj->second->components)
    {
        DeleteComponent(comp.first, objID);
    }
    
    Game::Instance().scene->_allObjHubs.erase(obj);
    delete obj->second;
};
