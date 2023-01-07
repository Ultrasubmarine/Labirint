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

#include <set>
#include <functional>   // std::bind

#include "SceneObject.hpp"
#include "Render.hpp"

#include <vector>

class Scene
{
    std::set<SceneObject*> _allObjects; // structure?? vector, set?
    
    std::set<SceneObject*> _tick;
public:
    
    void OnDeleteObject(SceneObject* obj);
    void OnCreateObject(SceneObject* obj);
    
    void Tick();
        
    //test
    void TestLoadObject();
};

#endif /* Scene_hpp */
