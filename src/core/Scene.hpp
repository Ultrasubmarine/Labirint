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

#include "GameObject.hpp"
#include "RenderSystem.hpp"

#include <vector>
#include <list>

struct SceneSettings
{
    //smth
};
class Scene
{
    
    std::list<GameObject*> _allObjects; // structure?? vector, set?
    
    std::list<GameObject*> _tick;
public:
    
    void Load(std::list<GameObject*> &obj, SceneSettings settings);
    
    
    void OnDeleteObject(GameObject* obj);
    void OnCreateObject(GameObject* obj);
    
    void Tick(float delta_tick);
        
    //test
    void TestLoadObject();
    
    GameObject* GetFirstObj();
};

#endif /* Scene_hpp */
