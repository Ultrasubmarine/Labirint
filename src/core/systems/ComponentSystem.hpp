//
//  ComponentSystem.hpp
//  Labirint
//
//  Created by marina porkhunova on 22.01.2023.
//

#ifndef ComponentSystem_hpp
#define ComponentSystem_hpp

#include <stdio.h>
#include <list>
#include <map>

#include "Component.hpp"
#include "FactoryMethod.hpp"

using namespace std;

class ComponentSystem
{
    static map<TypeId, map<SId,Component*>> _allComponents;
    static list<TypeId> _updateableComponents;
    
    static FactoryMethod<TypeId, Component, SId> _factory;
    
public:
    static Component* CreateComponent(TypeId componentID, SId objectID);
    static void DeleteComponent(TypeId componentID, SId objectID);
    
    static Component* GetComponentBySid(TypeId componentID, SId objectID);
    static bool IsComponentExist(TypeId componentID, SId objectID);
    
    static void UpdateComponents(double deltaTime);
    
    static void RegisterUpdateComponent(TypeId componentID);
    static bool RegisterComponent(const TypeInfo &typeInfo, TCreateComponent createFunc);
};

#endif /* ComponentSystem_hpp */
