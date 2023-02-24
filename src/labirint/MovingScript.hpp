//
//  MovingScript.hpp
//  Labirint
//
//  Created by marina porkhunova on 28.01.2023.
//

#ifndef MovingScript_hpp
#define MovingScript_hpp

#include <stdio.h>
#include "Transform.hpp"

class MovingScript : public Component
{
    COMPONENT_BODY(MovingScript)
 
    int x_max = 300, x_min = 5;
    int direct = 1;
    int pixel_speed = 150; // pixel/second
    
    Transform *t;
public:
    void Init() override;
    void Update(double deltaTime) override;
};
#endif /* MovingScript_hpp */
