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

#define SCENE_OBJ_NOTHING       0x0
#define SCENE_OBJ_RENDER        0x1
#define SCENE_OBJ_TICK          0x2
#define SCENE_OBJ_RENDER_TICK   0x1 | 0x2



class SceneObject
{
    uint _settings;
    pair<int,int> _position;
    
public:
    
    SceneObject(uint SCENE_OBJ_SETTINGS) : _settings{SCENE_OBJ_SETTINGS}
    {
        OnCreated.Call(this);
    };
    
    ~SceneObject()
    {
        OnDeleted.Call(this);
    }
    
    uint GetSettings();

    pair<int,int> GetPosition();
    void SetPosition(int x,int y);
    
    CallBack<SceneObject*> OnCreated;
    CallBack<SceneObject*> OnDeleted;
};




#endif /* SceneObject_hpp */
