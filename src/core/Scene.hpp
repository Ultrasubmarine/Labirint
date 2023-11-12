//
//  Scene.hpp
//  Labirint
//
//  Created by marina porkhunova on 20.12.2022.
//

#ifndef Scene_hpp
#define Scene_hpp

#include <stdio.h>
#include <map>

#include "GameHub.hpp"

class Scene
{
    const std::string _name;
    //TODO <ScenePart, list<GameHub*>>?
    std::map<SId, GameHub::Ptr> _allHubs;
    
public:
    Scene() = delete;
    ~Scene();
    Scene(std::string& name);

    GameHub::WeakPtr CreateGameHub(const char* uniqueName);
    void DeleteGameHub(GameHub* hub);
    void DeleteAllGameHubs();
    
    GameHub* GetGameHub(SId id);
    const std::string& GetName();
};

#endif /* Scene_hpp */
