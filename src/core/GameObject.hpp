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
#include "StringID.hpp"


class GameObject
{
    uint _settings;
    
    sid _sid;
protected:
    Transform _transform;
    Image* _image;
    
public:
    
    GameObject(sid sid, uint SCENE_OBJ_SETTINGS);
    virtual ~GameObject();
    
    uint GetSettings();
    Transform& GetTransform();
    Image* GetImage();
    
    void virtual Tick(float delta_tick);
    void SetImageTexture(SDL_Texture* texture, SDL_Rect* src = NULL);
};
#endif /* SceneObject_hpp */
