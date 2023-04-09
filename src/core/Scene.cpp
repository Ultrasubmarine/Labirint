//
//  Scene.cpp
//  Labirint
//
//  Created by marina porkhunova on 20.12.2022.
//

#include "Scene.hpp"
#include "CoreFunctions.hpp"
#include "Debug.h"

Scene::Scene(std::string& s_name)
{
    name = std::string(s_name);
}

Scene::~Scene()
{
    vector<SId> allkeys;
    for(auto o : _allHubs)
    {
        allkeys.push_back(o.first);
    }
    
    for(auto k : allkeys)
    {
        DeleteGameHub(k);
    }
    LOG("Delete scene");
}

GameHub* Scene::CreateGameHub(const char* uniqueName)
{
    auto id = SID(uniqueName);
    
    if(_allHubs.find(id) != _allHubs.end())
    {
        LOG_ERROR("Scene::CreateGameHub(): object " + std::string(uniqueName) + " already created");
        return nullptr;
    }
      
    GameHub* hub = new GameHub(id);
    _allHubs[id] = hub;
    
    return hub;
}

void Scene::DestroyGameHub(GameHub* hub)
{
    auto sid = hub->GetSid();
    _allHubs.erase(sid);
    DESTROY_SID(sid);
    delete hub;
}

GameHub* Scene::GetGameHub(SId id)
{
    if(auto it = _allHubs.find(id); it != _allHubs.end())
        return it->second;
    return nullptr;
}


const std::string& Scene::GetName()
{
    return name;
}


