//
//  Component.hpp
//  Labirint
//
//  Created by marina porkhunova on 19.01.2023.
//

#ifndef Component_hpp
#define Component_hpp

#include <stdio.h>
#include <typeinfo>
#include <typeindex>

#include "StringID.hpp"
#include "TypeInfo.hpp"

using namespace std;

#define DEFAULT_COMPONENT_VALUE Component

// combine all macro to component body
#define COMPONENT_BODY(CLASS_NAME, ...) \
REGISTER_COMPONENT_IN_FACTORY_H(CLASS_NAME)\
SET_COMPONENT_CONSTRUCTORS(CLASS_NAME __VA_OPT__(, __VA_ARGS__), DEFAULT_COMPONENT_VALUE)
//------------------------------------------


//combine all macro to component cpp
#define COMPONENT_CPP(CLASS_NAME) \
bool CLASS_NAME::c_register = REGISTER_COMPONENT_IN_FACTORY_CPP(CLASS_NAME) && REGISTER_TYPE(CLASS_NAME);
//------------------------------------------


// adjust constructors
#define SET_COMPONENT_CONSTRUCTORS(CLASS_NAME, BASE_CLASS_COMPONENT, ...) \
public: \
    CLASS_NAME() = delete;\
    CLASS_NAME(sid id): BASE_CLASS_COMPONENT(id){ Init();}; \
private:
//------------------------------------------


// register component in ComponentFactory
#define REGISTER_COMPONENT_IN_FACTORY_H(CLASS_NAME) \
public: \
    static Component* CreateComponent(sid id) { return  new CLASS_NAME(id);} \
private: \
    static bool c_register;

#define REGISTER_COMPONENT_IN_FACTORY_CPP(CLASS_NAME) RegisterComponent(type_index(typeid(CLASS_NAME)), &CLASS_NAME::CreateComponent)
//------------------------------------------

 
class Component
{
protected:
    sid _sid;
    TypeInfo* _typeInfo;
    
    // Use instead of constructor for initialization
    virtual void Init(){};
public:
    Component() = delete;
    Component(sid id);
    const sid GetSid();
    
    const TypeInfo* GetTypeInfo();
};

using TCreateComponent = Component*(*)(sid);
bool RegisterComponent(type_index componentID, TCreateComponent createFunc);

#endif /* Component_hpp */
