//
//  CoreFunctions.cpp
//  Labirint
//
//  Created by marina porkhunova on 07.01.2023.
//

#include "CoreFunctions.hpp"
#include "Game.hpp"
#include <map>

#include "MovingScript.hpp"
//void DeleteSceneObject(GameObject* obj)
//{
//    Game::Instance().scene->OnDeleteObject(obj);
//    if(obj->GetSettings() & SCENE_OBJ_RENDER)
//        Game::Instance().renderSystem->DeleteRenderObj(obj);
//    
//    delete obj;
//};


GameObjectHUB* CreateGameObjectHUB(const char* uniqueName, std::list<type_index> &components)
{

    auto id = SID(uniqueName);
    GameObjectHUB* hub = new GameObjectHUB(id);
    
    Component* c;
    Script* s;
    for(auto comp_type: components)
    {
       
       if(comp_type == type_index(typeid(Transform)) )
       {
           c = CreateComponent<Transform>(id);
       }
       else if(comp_type == type_index(typeid(Image)) )
       {
           auto im = CreateComponent<Image>(id);
           Game::Instance().renderSystem->AddRenderObj(id, im);
           c = im;
       }
       else if(comp_type == type_index(typeid(MovingScript)) )
       {
           s = CreateComponent<MovingScript>(id);
       
           c = s;
       }
       else
       {
           cout<<"error: component type didn't found";
           continue;
       }
        
  
        //add in upd list
//        if(s)
//        {
//            if(&s->Script::Update == &Script::Update)
//                ComponentSystem::_updateableComponents.push_front(comp_type);
//            s = nullptr;
//        }
        hub->components[comp_type] = c;
      
    }
    
    Game::Instance().scene->_allObjHubs[id] = hub;
    return hub;
};


void DeleteSceneObjectHUB(sid objID)
{
    auto obj = Game::Instance().scene->_allObjHubs.find(objID);
    
    if(obj == Game::Instance().scene->_allObjHubs.end())
        return;
    
    for(auto comp : obj->second->components)
    {
        DeleteComponent(comp.first, objID);
    }
    
    Game::Instance().scene->_allObjHubs.erase(obj);
    delete obj->second;
};
