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


//TODO static obj
class ComponentSystem
{
    static map<TypeId, map<SId,Component*>> _allComponents;
    static list<TypeId> _updateableComponents;
    static list<TypeId> _drawComponents;
    
    static FactoryMethod<TypeId, Component, SId> _factory;
    
public:
    static Component* CreateComponent(TypeId componentID, SId objectID);
    static void DeleteComponent(TypeId componentID, SId objectID);
    
    static Component* GetComponentBySid(TypeId componentID, SId objectID);
    static bool IsComponentExist(TypeId componentID, SId objectID);
    static const map<SId,Component*>* GetAllComponentByType(TypeId componentID);
    
    static void UpdateComponents(double deltaTime);
    static list<TypeId>& GetDrawComponents();
    
    static void RegisterUpdateComponent(TypeId componentID);
    static void RegisterDrawComponent(TypeId componentID);
    static bool RegisterComponent(const TypeInfo &typeInfo, TCreateComponent createFunc);
    
    
    static list<TypeId>& DrawList();
};

#endif /* ComponentSystem_hpp */
