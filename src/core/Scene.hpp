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
    std::map<SId, GameHub*> _allHubs;
    std::map<SId, GameHub::Ptr> _allHubsSmart;
    
public:

    Scene() = delete;
    ~Scene();
    Scene(std::string& name);

    GameHub* AddGameHub(const char* uniqueName);
    void RemoveGameHub(GameHub* hub);
    
    GameHub* GetGameHub(SId id);
    const std::string& GetName();
};

#endif /* Scene_hpp */
