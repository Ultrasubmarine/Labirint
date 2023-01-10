//
//  main.cpp
//  FortuneCookie
//
//  Created by marina porkhunova on 26.10.2022.
//

#include <stdio.h>

#include "CoreFunctions.hpp"
#include "Game.hpp"
#include "Frog.hpp"

int main(int argc, char *argv[])
{

    if(Game::Instance().Init())
        return -1;

   auto frog = CreateSceneObject<SceneObject>(SCENE_OBJ_RENDER);
   frog->SetImageTexture(Game::Instance().textureLoader->GetTexture("frog"));
   frog->GetTransform().SetPosition(5,50);

   Frog* reallyFrog =  CreateSceneObject<Frog>(SCENE_OBJ_RENDER_TICK);
   reallyFrog->SetImageTexture(Game::Instance().textureLoader->GetTexture("frog"));
   reallyFrog->GetTransform().SetPosition(100,50);
    
    
    Game::Instance().Loop();
    return 0;
}
