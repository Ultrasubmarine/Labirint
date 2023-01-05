//
//  Scene.cpp
//  Labirint
//
//  Created by marina porkhunova on 20.12.2022.
//

#include "Scene.hpp"
#include "GetPath.h"

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
        _render.erase(obj);
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
        _render.insert(obj);
    }
};

void Scene::Render(SDL_Renderer *render)
{
    for(auto obj : _render)
    {
        if(obj->texture)
        SDL_RenderCopy(render, obj->texture, &obj->srcrect, &obj->dstrect);
        //<#const SDL_Rect *dstrect#>)
    }
};

void Scene::TestLoadObject(SDL_Renderer *render)
{
    auto frog = CreateSceneObject(this, SCENE_OBJ_RENDER);
    

    char *image_path = GetPath(CFSTR("resources/images/frog"), CFSTR("bmp"));
    //Put your own bmp image here
    SDL_Surface *bmpSurf = SDL_LoadBMP(image_path);
    
    free(image_path);
    SDL_Texture *bmpTex = SDL_CreateTextureFromSurface(render, bmpSurf);
    SDL_FreeSurface(bmpSurf);
    
    
   // SDL_Rect r =
    frog->SetTexture(bmpTex);
    
};

