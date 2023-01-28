//
//  Script.hpp
//  Labirint
//
//  Created by marina porkhunova on 22.01.2023.
//

#ifndef Script_hpp
#define Script_hpp

#include <stdio.h>
#include "Component.hpp"

class Script : public Component
{
public:
    Script(sid id): Component(id){};
    virtual void Init() {};
    virtual void Update() {};
};
#endif /* Script_hpp */
