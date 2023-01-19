//
//  Component.hpp
//  Labirint
//
//  Created by marina porkhunova on 19.01.2023.
//

#ifndef Component_hpp
#define Component_hpp

#include <stdio.h>
#include "StringID.hpp"

class Component
{
    sid _sid;
    
public:
    Component(sid id);
    const sid GetSid();

};
#endif /* Component_hpp */
