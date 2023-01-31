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
    
   // COMPONENT_BODY(Script)
    REGISTER_COMPONENT_H(Script)
   // COMPONENT_BODY(Script)
    SET_COMPONENT_CONSTRUCTORS(Script, Component)
public:
  //  Script(sid id): Component(id){};
    void Init() override{} ;
    virtual void Update() {};
};
#endif /* Script_hpp */
