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


// combine all macro for component body
#define DEFAULT_COMPONENT_VALUE Component
#define COMPONENT_BODY(CLASS_NAME, ...) \
REGISTER_COMPONENT_H(CLASS_NAME)\
SET_COMPONENT_CONSTRUCTORS(CLASS_NAME __VA_OPT__(, __VA_ARGS__), DEFAULT_COMPONENT_VALUE)
//------------------------------------------


// adjust constructors
#define SET_COMPONENT_CONSTRUCTORS(CLASS_NAME, BASE_CLASS_COMPONENT, ...) \
public: \
    CLASS_NAME() = delete;\
    CLASS_NAME(sid id): BASE_CLASS_COMPONENT(id){ Init();}; \
private:
//------------------------------------------


// register component in ComponentFactory
#define REGISTER_COMPONENT_H(CLASS_NAME) \
public: \
    static Component* CreateComponent(sid id) { return  new CLASS_NAME(id);} \
private: \
    static bool c_register;


#define REGISTER_COMPONENT_CPP(CLASS_NAME) \
bool CLASS_NAME::c_register = ComponentFactory::Register(type_index(typeid(CLASS_NAME)), &CLASS_NAME::CreateComponent);
//------------------------------------------


class Component
{
protected:
    sid _sid;
    
public:
    Component() = delete;
    Component(sid id);
    const sid GetSid();
    
    // Use instead of constructor for initialization
    virtual void Init(){};
};

#endif /* Component_hpp */
