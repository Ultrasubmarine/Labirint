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
    //TODO <ScenePart, list<GameHub*>>?
    std::map<SId, GameHub*> _allHubs;
    
public:

//    void Load(sceneSV)
//    {
//        
//    }
    GameHub* CreateGameHub(const char* uniqueName);
    void DestroyGameHub(GameHub* hub);
    
    GameHub* GetGameHub(SId id);
};

#endif /* Scene_hpp */
