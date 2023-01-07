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
    _allObjects.erase(obj);
    
    auto settings = obj->GetSettings();
    
    if(settings & SCENE_OBJ_TICK)
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
};

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

