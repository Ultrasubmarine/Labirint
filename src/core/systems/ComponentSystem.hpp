//
//  ComponentSystem.hpp
//  Labirint
//
//  Created by marina porkhunova on 22.01.2023.
//

#ifndef ComponentSystem_hpp
#define ComponentSystem_hpp

#include <stdio.h>
#include <unordered_map>
#include <list>


#include "Component.hpp"
#include "FactoryMethod.hpp"

using namespace std;
class GameHub;

class ComponentSystem
{
    static unordered_map<TypeId, unordered_map<SId,Component*>> _allComponents;
        
    static list<TypeId>& DrawList();
    static list<TypeId>& UpdateList();
    static FactoryMethod<TypeId, Component, SId>& ComponentFactory();
    
public:
    static Component* CreateComponent(TypeId componentID, SId objectID);
    static void DeleteComponent(TypeId componentID, SId objectID);
    
    static bool IsComponentExist(TypeId componentID, SId objectID);
    static Component* GetComponentBySid(TypeId componentID, SId objectID);
    
    static const unordered_map<SId,Component*>* GetAllComponentByType(TypeId componentID);
    static const list<TypeId>& GetDrawList();
    static const list<TypeId>& GetUpdateList();
    
    static void UpdateComponents(double deltaTime);
    
    static void RegisterUpdateComponent(TypeId componentID);
    static void RegisterDrawComponent(TypeId componentID);
    static bool RegisterComponent(const TypeInfo &typeInfo, TCreateComponent createFunc);
    
    static void OnGameHubDeleted(GameHub* hub);
};

#endif /* ComponentSystem_hpp */
