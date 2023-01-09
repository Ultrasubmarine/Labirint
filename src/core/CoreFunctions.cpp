//
//  CoreFunctions.cpp
//  Labirint
//
//  Created by marina porkhunova on 07.01.2023.
//

#include "CoreFunctions.hpp"
#include "Scene.hpp"
#include "Render.hpp"


void DeleteSceneObject(SceneObject* obj)
{
    Game::Instance().scene->OnDeleteObject(obj);
    if(obj->GetSettings() & SCENE_OBJ_RENDER)
        Game::Instance().renderSystem->DeleteRenderObj(obj);
    
    delete obj;
};
