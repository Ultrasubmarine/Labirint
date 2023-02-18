//
//  SceneManager.cpp
//  Labirint
//
//  Created by marina porkhunova on 18.02.2023.
//

#include "CoreFunctions.hpp"
#include "SceneManager.hpp"
#include "Game.hpp"

SceneManager::~SceneManager()
{
    DestroyCurrentScene();
}

void SceneManager::DestroyCurrentScene()
{
    delete currentScene;
}

Scene* SceneManager::LoadScene(std::string& s_name)
{
    if(currentScene)
        DestroyCurrentScene();
    
    currentScene = new Scene(s_name);
    auto sceneSettings =  Game::Instance().resourceManager->GetScene(s_name);
    if(!sceneSettings)
    {
        printf("error: SceneManager::LoadScene() fail load scene ""%s""\n", s_name.c_str());
        return nullptr;
    }
    
    auto hubs =(*sceneSettings)["hubs"];
    for (json::iterator it = hubs.begin(); it != hubs.end(); ++it) {
  
         const char* n =  it.value()["name"].get<std::string>().c_str();
         auto objectHub =  CreateGameHub(n) ;
        
        for (json::iterator it_comp = it.value()["components"].begin(); it_comp != it.value()["components"].end(); ++it_comp) {
            
            uint32_t id;
            if(it.value()["cid"].empty())
            {
                auto name_comp =it_comp.value()["name"].get<std::string>().c_str();
                id = TYPE_ID_BY_PTR_STR(name_comp);
            }
            else {
                id = it.value()["cid"].get<uint32_t>();
            }
            
            auto c = CreateComponent(id, objectHub);
            c->Serialize(it_comp.value());
        }
    }
    delete sceneSettings;
    
    return currentScene;
}

Scene* SceneManager::GetCurrentScene()
{
    return currentScene;
}



