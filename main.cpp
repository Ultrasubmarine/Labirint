//
//  main.cpp
//  FortuneCookie
//
//  Created by marina porkhunova on 26.10.2022.
//

#include <stdio.h>

#include "CoreFunctions.hpp"
#include "Game.hpp"
#include "MovingScript.hpp"
#include "ComponentFactory.hpp"

int main(int argc, char *argv[])
{
 
    const char* uniqueName ="fff";
    Component* t = ComponentFactory::Create(type_index(typeid(Image)), SID(uniqueName));
    if(Game::Instance().Init())
        return -1;

    std::list<type_index> components = {type_index(typeid(Transform)),type_index(typeid(Image)), type_index(typeid(MovingScript)) };
    auto hub = CreateGameObjectHUB("fri", components);
    
    auto image = GetComponent<Image>(hub->_id);
    image->SetTexture(Game::Instance().textureLoader->GetTexture("frog"));
    
    auto transform = GetComponent<Transform>(hub->_id);
    transform->SetPosition(5,50);
   // hub->components
    
//    auto frog = CreateSceneObject<GameObject>("frog",SCENE_OBJ_RENDER);
//    frog->SetImageTexture(Game::Instance().textureLoader->GetTexture("frog"));
//    frog->GetTransform().SetPosition(5,50);
//
//    Frog* reallyFrog =  CreateSceneObject<Frog>("realFrog",SCENE_OBJ_RENDER_TICK);
//    reallyFrog->SetImageTexture(Game::Instance().textureLoader->GetTexture("frog"));
//    reallyFrog->GetTransform().SetPosition(100,50);

    Game::Instance().Loop();
    return 0;
}
