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


#define REGISTER_COMPONENT_H(CLASS_NAME) \
public: \
    static Component* CreateComponent(sid id) { return  new CLASS_NAME(id);} \
private: \
    static bool c_register;


#define REGISTER_COMPONENT_CPP(CLASS_NAME) \
bool CLASS_NAME::c_register = ComponentFactory::Register(type_index(typeid(CLASS_NAME)), &CLASS_NAME::CreateComponent);


class Component
{
protected:
    sid _sid;
    
public:
    // TODO delete default constructor Component();
    Component(sid id);
    const sid GetSid();
};

#endif /* Component_hpp */
