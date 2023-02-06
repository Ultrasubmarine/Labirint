//
//  Component.hpp
//  Labirint
//
//  Created by marina porkhunova on 19.01.2023.
//

#ifndef Component_hpp
#define Component_hpp

#include <stdio.h>

#include "StringId.hpp"
#include "TypeId.hpp"

using namespace std;

#define DEFAULT_COMPONENT_VALUE Component

// combine all macro to component body
#define COMPONENT_BODY(CLASS_NAME, ...) \
REGISTER_COMPONENT_IN_FACTORY_H(CLASS_NAME)\
SET_COMPONENT_CONSTRUCTORS(CLASS_NAME __VA_OPT__(, __VA_ARGS__), DEFAULT_COMPONENT_VALUE)
//------------------------------------------


//combine all macro to component cpp
#define COMPONENT_CPP(CLASS_NAME) \
bool CLASS_NAME::c_register = REGISTER_TYPE(CLASS_NAME) && \
                              REGISTER_COMPONENT_IN_FACTORY_CPP(CLASS_NAME) && \
                              REGISTER_UPDATE_CPP(CLASS_NAME);
//------------------------------------------


// adjust constructors
#define SET_COMPONENT_CONSTRUCTORS(CLASS_NAME, BASE_CLASS_COMPONENT, ...) \
public: \
    CLASS_NAME() = delete;\
    CLASS_NAME(SId id): BASE_CLASS_COMPONENT(id){ Init(); \
_typeInfo = TYPE_INFO(CLASS_NAME); \
}; \
private:
//------------------------------------------


// register component in ComponentFactory
#define REGISTER_COMPONENT_IN_FACTORY_H(CLASS_NAME) \
public: \
    static Component* CreateComponent(SId id) { return  new CLASS_NAME(id);} \
private: \
    static bool c_register;

#define REGISTER_COMPONENT_IN_FACTORY_CPP(CLASS_NAME) RegisterComponent( #CLASS_NAME, &CLASS_NAME::CreateComponent)
//------------------------------------------

// register update
#define REGISTER_UPDATE_CPP(CLASS_NAME) \
(( &CLASS_NAME::Update != &DEFAULT_COMPONENT_VALUE::Update) ? RegisterUpdate(TYPE_ID(CLASS_NAME)) : true)

class Component
{
protected:
    SId _sid;
    const TypeInfo* _typeInfo;
    
    // Use instead of constructor for initialization
    virtual void Init(){};
public:
    Component() = delete;
    Component(SId id);
    const SId GetSid();
    
    const TypeInfo* GetTypeInfo();
    
    virtual void Update() {};
};


using TCreateComponent = Component*(*)(SId);
bool RegisterComponent(const char *componentName, TCreateComponent createFunc);
bool RegisterUpdate(TypeId componentID);

#endif /* Component_hpp */
