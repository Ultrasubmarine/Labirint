//
//  Scene.hpp
//  Labirint
//
//  Created by marina porkhunova on 20.12.2022.
//

#ifndef Scene_hpp
#define Scene_hpp

#include <stdio.h>
#include <SDL2/SDL.h>

#include <functional>   // std::bind

#include "GameHub.hpp"
#include "RenderSystem.hpp"

#include <map>


struct SceneSettings
{
    //smth
};
class Scene
{
  //  std::list<GameObject*> _allObjects; // structure?? vector, set?

public:
    
//    void Load(std::list<GameObject*> &obj, SceneSettings settings);
//    
//    
//    void OnDeleteObject(GameObject* obj);
//    void OnCreateObject(GameObject* obj);
        
    //test
    void TestLoadObject();
    
   // GameObject* GetFirstObj();
    
    std::map<SId, GameHub*> _allHubs;
};

#endif /* Scene_hpp */
