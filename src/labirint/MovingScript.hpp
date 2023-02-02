//
//  MovingScript.hpp
//  Labirint
//
//  Created by marina porkhunova on 28.01.2023.
//

#ifndef MovingScript_hpp
#define MovingScript_hpp

#include <stdio.h>
#include "Script.hpp"
#include "Transform.hpp"

class MovingScript : public Script
{
    COMPONENT_BODY(MovingScript, Script)
 
    int x_max = 300, x_min = 5;
    int direct = 1;
    
    Transform *t;
public:
    void Init() override;
    void Update() override;
};
#endif /* MovingScript_hpp */
