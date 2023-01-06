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
 
    //World
    //UI
    std::set<SceneObject*> _allObjects; // structure?? vector, set?
    
    std::set<SceneObject*> _render; // set? with render stuff
    std::set<SceneObject*> _tick;
    
    //Render
    //Tick
    
public:
    
    void OnDeleteObject(SceneObject* obj);
    void OnCreateObject(SceneObject* obj);
    
    void Render(SDL_Renderer *render);
    void Tick();
    
    
    //test
    void TestLoadObject(SDL_Renderer *render);
    
    // tmp
    RenderSystem* _RenderSystem;
};


SceneObject* CreateSceneObject(Scene* scene, uint SCENE_OBJ_SETTINGS);
void DeleteSceneObject(Scene* scene, SceneObject* obj);

#endif /* Scene_hpp */
