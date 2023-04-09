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

#include "json.hpp"

using json = nlohmann::json;

#define DEFAULT_COMPONENT_VALUE Component


/// Generating needed information to Component in body.
/// @param CLASS_NAME - current class type
/// @param ... - add parent class type if parent != Component
#define COMPONENT_BODY(CLASS_NAME, ...) \
COMPONENT_CREATE_METHOD(CLASS_NAME)\
COMPONENT_CONSTRUCTORS(CLASS_NAME __VA_OPT__(, __VA_ARGS__), DEFAULT_COMPONENT_VALUE)\
REGISTER_TYPE_BODY(CLASS_NAME)

/// Generating needed information to Component in cpp.
/// @param CLASS_NAME - current class type
#define COMPONENT_CPP(CLASS_NAME) \
bool CLASS_NAME::c_register =   REGISTER_TYPE(CLASS_NAME) && \
                                REGISTER_COMPONENT_IN_FACTORY(CLASS_NAME) && \
                                REGISTER_UPDATE(CLASS_NAME) && \
                                REGISTER_DRAW(CLASS_NAME);
                              

/// Generating constructors.
#define COMPONENT_CONSTRUCTORS(CLASS_NAME, BASE_CLASS_COMPONENT, ...) \
public: \
    CLASS_NAME() = delete;\
    CLASS_NAME(SId id): BASE_CLASS_COMPONENT(id){ Init(); \
_typeInfo = TYPE_INFO_BY_NAME(CLASS_NAME); \
}; \
private:

/// Generating CreateMethod
#define COMPONENT_CREATE_METHOD(CLASS_NAME) \
public: \
    static Component* CreateComponent(SId id) { return  new CLASS_NAME(id);} \
private: \
    static bool c_register;

///
#define REGISTER_COMPONENT_IN_FACTORY(CLASS_NAME) RegisterComponent( #CLASS_NAME, &CLASS_NAME::CreateComponent)

///
#define REGISTER_UPDATE(CLASS_NAME) \
( &CLASS_NAME::Update != &DEFAULT_COMPONENT_VALUE::Update) ? RegisterUpdate(TYPE_ID(CLASS_NAME)) : true

#define REGISTER_DRAW(CLASS_NAME) \
( &CLASS_NAME::Draw != &DEFAULT_COMPONENT_VALUE::Draw) ? RegisterDraw(TYPE_ID(CLASS_NAME)) : true 

//temp place
#include <SDL2/SDL.h>
class Component
{
protected:
    SId _sid;
    const TypeInfo* _typeInfo;
    
    /// Use instead of constructor for initialization
    virtual void Init(){};
public:
    Component() = delete;
    Component(SId id);
    virtual ~Component();
    
    const SId GetSid();
    const TypeInfo* GetTypeInfo();
    
    virtual void Update(double deltaTime) {};
    virtual void Draw(SDL_Renderer* render) {};
    
    virtual void Serialize(json &j) {};
    virtual void Deserialize(json &j) {};
    
};

using TCreateComponent = Component*(*)(SId);
bool RegisterComponent(const char *componentName, TCreateComponent createFunc);

bool RegisterUpdate(TypeId componentID);
bool RegisterDraw(TypeId componentID);

#endif /* Component_hpp */
