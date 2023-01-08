//
//  Frog.cpp
//  Labirint
//
//  Created by marina porkhunova on 08.01.2023.
//

#include "Frog.hpp"


Frog::Frog(uint SCENE_OBJ_SETTINGS): SceneObject(SCENE_OBJ_SETTINGS)
{
    
}

void Frog::Tick(float delta_tick)
{
    
    if( direct>0 && direct + _transform.GetPosition().x <= x_max)
        _transform.SetPosition(direct + _transform.GetPosition().x, 50);
    else if( direct<1 && direct + _transform.GetPosition().x >= x_min)
        _transform.SetPosition(direct + _transform.GetPosition().x, 50);
    else
        direct *= (-1);
           
}
