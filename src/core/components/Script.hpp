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
    COMPONENT_BODY(Script)
public:
  //  Script(sid id): Component(id){};
    void Init() override{} ;
    virtual void Update() {};
};
#endif /* Script_hpp */
