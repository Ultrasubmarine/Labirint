//
//  Scene.cpp
//  Labirint
//
//  Created by marina porkhunova on 20.12.2022.
//

#include "Scene.hpp"
//#include "GetPath.h"

void Scene::OnDeleteObject(SceneObject* obj)
{
    //delete children
    _allObjects.remove(obj);
    
    auto settings = obj->GetSettings();
    
    if(settings & SCENE_OBJ_TICK)
    {
        _tick.remove(obj);
    }
};

void Scene::OnCreateObject(SceneObject *obj)
{
    _allObjects.push_back(obj);
    
    auto settings = obj->GetSettings();
    
    if(settings & SCENE_OBJ_TICK)
    {
        _tick.push_back(obj);
    }
};

void Scene::Tick(float delta_tick)
{
    for(auto t: _tick)
    {
        t->Tick(delta_tick);
    }
}

void Scene::TestLoadObject()
{
//   auto frog = CreateSceneObject(this, SCENE_OBJ_RENDER);
//    
//
//    char *image_path = GetPath(CFSTR("resources/images/frog"), CFSTR("bmp"));
//    //Put your own bmp image here
//    SDL_Surface *bmpSurf = SDL_LoadBMP(image_path);
//    
//    free(image_path);
//    SDL_Texture *bmpTex = SDL_CreateTextureFromSurface(render, bmpSurf);
//    SDL_FreeSurface(bmpSurf);
//    
//    
//   // SDL_Rect r =
// //   frog->SetTexture(bmpTex);
    
};

SceneObject* Scene::GetFirstObj()
{
    return _allObjects.front();
}


