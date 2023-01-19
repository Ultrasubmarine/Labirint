//
//  ComponentFactory.hpp
//  Labirint
//
//  Created by marina porkhunova on 19.01.2023.
//

#ifndef ComponentFactory_hpp
#define ComponentFactory_hpp

#include <stdio.h>

#include "StringID.hpp"

#include "AllComponents.h"
#include "Component.hpp"


Component* CreateComponent(sid id, ComponentType type);


#endif /* ComponentFactory_hpp */
