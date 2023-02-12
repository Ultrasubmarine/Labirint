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


int main(int argc, char *argv[])
{

    const char* uniqueName ="fff";

    if(Game::Instance().Init())
        return -1;


    std::list<TypeId> components = {TYPE_ID(Transform), TYPE_ID(Image), TYPE_ID(MovingScript)};
    auto hub = CreateGameHub("fri", components);
    
    auto image = GET_COMPONENT(Image, hub->GetSid());
    std::string image_name = std::string("frog");
    image->SetTexture(Game::Instance().textureLoader->GetTexture(image_name));
   
    auto transform = GetComponent<Transform>(hub->GetSid(), TYPE_ID(Transform));
    transform->SetPosition(5,50);

    Game::Instance().Loop();
    return 0;
    
}
