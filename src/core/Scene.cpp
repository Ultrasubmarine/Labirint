//
//  Scene.cpp
//  Labirint
//
//  Created by marina porkhunova on 20.12.2022.
//

#include "Scene.hpp"
#include "CoreFunctions.hpp"
#include "Debug.h"

Scene::Scene(std::string& name) : _name(name)
{
}

Scene::~Scene()
{
    DeleteAllGameHubs();
    LOG("Delete scene");
}

GameHub::WeakPtr Scene::CreateGameHub(const char* uniqueName)
{
    auto id = SID(uniqueName);
    
    if(_allHubs.find(id) != _allHubs.end())
    {
        LOG_ERROR("Scene::CreateGameHub(): object " + std::string(uniqueName) + " already created");
        return GameHub::WeakPtr{};
    }
   
    GameHub::Ptr hub{ new GameHub(id),[this](GameHub* hub)
        {
            ComponentSystem::OnGameHubDeleted(hub);
            delete hub;}
        };
    _allHubs[id] = hub;
    
    return GameHub::WeakPtr{hub};
}

void Scene::DeleteGameHub(GameHub* hub)
{
    auto sid = hub->GetSid();
    _allHubs.erase(sid);
    DESTROY_SID(sid);
}

void Scene::DeleteAllGameHubs()
{
    _allHubs.clear();
}

GameHub* Scene::GetGameHub(SId id)
{
    if(auto it = _allHubs.find(id); it != _allHubs.end())
        return it->second.get();
    return nullptr;
}


const std::string& Scene::GetName()
{
    return _name;
}


