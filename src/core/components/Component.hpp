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

#define  NUMARGS(...)  (sizeof((int[]){0, ##__VA_ARGS__})/sizeof(int)-1)
//#define NUMARGS(...)  (sizeof((int[]){__VA_ARGS__})/sizeof(int))
#define STANDART_BASE Component
//#define SET_BASE(...) __VA_OPT__(

#define COMPONENT_BODY2(CLASS_NAME, ...) MAC_COMPONENT_CONSTRUCTOR(CLASS_NAME __VA_OPT__(, __VA_ARGS__))

#define COMPONENT_BODY(CLASS_NAME, ...) __VA_OPT__(MAC)_COMPONENT_CONSTRUCTOR(CLASS_NAME __VA_OPT__(, __VA_ARGS__))

#define MAC_COMPONENT_CONSTRUCTOR_(CLASS_NAME, BASE_COMPONENT)  SET_COMPONENT_CONSTRUCTORS(CLASS_NAME, BASE_COMPONENT)
#define _COMPONENT_CONSTRUCTOR(CLASS_NAME) SET_COMPONENT_CONSTRUCTORS(CLASS_NAME, Component)


#define COMPONENT_BODY_0(CLASS_NAME) \
REGISTER_COMPONENT_H(CLASS_NAME)\
SET_COMPONENT_CONSTRUCTORS(CLASS_NAME, Component)

#define COMPONENT_BODY_1(CLASS_NAME, __VA_ARGS__) \
REGISTER_COMPONENT_H(CLASS_NAME, __VA_ARGS__) \
SET_COMPONENT_CONSTRUCTORS(CLASS_NAME, __VA_ARGS__)


#define SET_COMPONENT_CONSTRUCTORS(CLASS_NAME, BASE_CLASS_COMPONENT) \
public: \
    CLASS_NAME() = delete;\
    CLASS_NAME(sid id): BASE_CLASS_COMPONENT(id){ Init();}; \
private: 

#define REGISTER_COMPONENT_H(CLASS_NAME) \
public: \
    static Component* CreateComponent(sid id) { return  new CLASS_NAME(id);} \
private: \
    static bool c_register;


#define REGISTER_COMPONENT_CPP(CLASS_NAME) \
bool CLASS_NAME::c_register = ComponentFactory::Register(type_index(typeid(CLASS_NAME)), &CLASS_NAME::CreateComponent);

#define REGISTER_COMPONENT_ID_H(CLASS_NAME) \
public: \
    virtual sid GetTypeID() override; \
private:

#define REGISTER_COMPONENT_ID_CPP(CLASS_NAME) \
sid CLASS_NAME::GetTypeID() {\
 static \
}

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
