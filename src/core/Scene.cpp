//
//  Scene.cpp
//  Labirint
//
//  Created by marina porkhunova on 20.12.2022.
//

#include "Scene.hpp"


SceneObject* CreateSceneObject(Scene* scene, uint SCENE_OBJ_SETTINGS)
{
    SceneObject* tmp = new SceneObject(SCENE_OBJ_SETTINGS);
    scene->OnCreateObject(tmp);
    
    return tmp;
};


void DeleteSceneObject(Scene* scene, SceneObject* obj)
{
    scene->OnDeleteObject(obj);
    
    delete obj;
};


void Scene::OnDeleteObject(SceneObject* obj)
{
    //delete children
    _allObjects.erase(obj);
    
    auto settings = obj->GetSettings();
    
    if(settings & SCENE_OBJ_TICK)
    {
        _tick.erase(obj);
    }
    if(settings & SCENE_OBJ_RENDER)
    {
        _tick.erase(obj);
    }
};

void Scene::OnCreateObject(SceneObject *obj)
{
    _allObjects.insert(obj);
    
    auto settings = obj->GetSettings();
    
    if(settings & SCENE_OBJ_TICK)
    {
        _tick.insert(obj);
    }
    if(settings & SCENE_OBJ_RENDER)
    {
        _tick.insert(obj);
    }
};

void Scene::Render()
{
    
};


