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
//#include "TypeInfo.hpp"

int main(int argc, char *argv[])
{
 
  //  REGISTER_TYPE(Image)
    
    const char* uniqueName ="fff";
    
    if(Game::Instance().Init())
        return -1;

    std::list<type_index> components = {type_index(typeid(Transform)),type_index(typeid(Image)), type_index(typeid(MovingScript)) };
    auto hub = CreateGameObjectHUB("fri", components);
    
    auto image = GetComponent<Image>(hub->GetSid());
    image->SetTexture(Game::Instance().textureLoader->GetTexture("frog"));
    
    auto transform = GetComponent<Transform>(hub->GetSid());
    transform->SetPosition(5,50);

    Game::Instance().Loop();
    return 0;
}
