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
    if(Game::Instance().Init())
        return -1;

    Game::Instance().Loop();    
    return 0;
}
