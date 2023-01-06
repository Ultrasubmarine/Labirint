//
//  SceneObject.hpp
//  Labirint
//
//  Created by marina porkhunova on 20.12.2022.
//

#ifndef SceneObject_hpp
#define SceneObject_hpp

#include <stdio.h>
#include <list>

#include "CallBack.hpp"
#include "Transform.hpp"
#include "Image.hpp"

#define SCENE_OBJ_NOTHING       0x0
#define SCENE_OBJ_RENDER        0x1
#define SCENE_OBJ_TICK          0x2
#define SCENE_OBJ_RENDER_TICK   (SCENE_OBJ_RENDER | SCENE_OBJ_TICK)

#include <SDL2/SDL.h>

class SceneObject
{
    uint _settings;
    Transform _transform;
    
    Image* _image;
    
public:
    
    SceneObject(uint SCENE_OBJ_SETTINGS) : _settings{SCENE_OBJ_SETTINGS}
    {
        OnCreated.Call(this);
    };
    
    ~SceneObject()
    {
        OnDeleted.Call(this);
        
        if(_image)
            delete _image;
    }
    
    uint GetSettings();

    pair<int,int> GetPosition();
    void SetPosition(int x,int y);
    
    CallBack<SceneObject*> OnCreated;
    CallBack<SceneObject*> OnDeleted;
    
    
    
    //temp place for this stuff    
    SDL_Texture *texture;
    SDL_Rect srcrect;
    SDL_Rect dstrect;

    
    
    
//    dstrect.x = 640/2;      // transform pos
//    dstrect.y = 480/2;      // transform pos
//    dstrect.w = srcrect.w;  // transform scale * srcrect.w
//    dstrect.h = srcrect.h;  // transform scale * srcrect.h
    
    //transform
    //texture
    
    void SetTexture(SDL_Texture* texture);
    void SetRect();
    
    Transform& GetTransform();
    Image* GetImage();
};




#endif /* SceneObject_hpp */
