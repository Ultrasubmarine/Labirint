//
//  CoreFunctions.cpp
//  Labirint
//
//  Created by marina porkhunova on 07.01.2023.
//

#include "CoreFunctions.hpp"
#include "Scene.hpp"
#include "Render.hpp"

//static Game* game;

void InitGame(Game* g)
{
    game = g;    
};

SceneObject* CreateSceneObject(uint SCENE_OBJ_SETTINGS)
{
    SceneObject* tmp = new SceneObject(SCENE_OBJ_SETTINGS);
    
    game->scene->OnCreateObject(tmp);
    if(SCENE_OBJ_SETTINGS & SCENE_OBJ_RENDER)
        game->renderSystem->AddRenderObj(tmp);
    //    game->renderSystem->AddRenderObj(tmp);
    
    return tmp;
};


void DeleteSceneObject(SceneObject* obj)
{
    game->scene->OnDeleteObject(obj);
   // if(obj->GetSettings() & SCENE_OBJ_RENDER)
    //    game->renderSystem->DeleteRenderObj(obj);
    
    delete obj;
};


#include "Frog.hpp"
SceneObject* CreateSceneFrog(uint SCENE_OBJ_SETTINGS)
{
    
    SceneObject* tmp = new Frog(SCENE_OBJ_SETTINGS);
    
    game->scene->OnCreateObject(tmp);
    if(SCENE_OBJ_SETTINGS & SCENE_OBJ_RENDER)
        game->renderSystem->AddRenderObj(tmp);
    //    game->renderSystem->AddRenderObj(tmp);
    
    return tmp;
}
