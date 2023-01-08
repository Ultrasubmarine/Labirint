//
//  Frog.hpp
//  Labirint
//
//  Created by marina porkhunova on 08.01.2023.
//

#ifndef Frog_hpp
#define Frog_hpp

#include <stdio.h>
#include "SceneObject.hpp"

class Frog : public SceneObject
{
    
    int x_max = 300, x_min = 5;
    int direct = 1;
public:
    Frog(uint SCENE_OBJ_SETTINGS);
    void Tick(float delta_tick) override;
};
#endif /* Frog_hpp */
