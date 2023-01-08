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

#include "SceneObject.hpp"
#include "Render.hpp"

#include <vector>
#include <list>
class Scene
{
    std::list<SceneObject*> _allObjects; // structure?? vector, set?
    
    std::list<SceneObject*> _tick;
public:
    
    void OnDeleteObject(SceneObject* obj);
    void OnCreateObject(SceneObject* obj);
    
    void Tick(float delta_tick);
        
    //test
    void TestLoadObject();
    
    SceneObject* GetFirstObj();
};

#endif /* Scene_hpp */
