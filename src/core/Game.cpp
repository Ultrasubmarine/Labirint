//
//  Game.cpp
//  
//
//  Created by marina porkhunova on 20.12.2022.
//

#include "Game.hpp"
#include <SDL2/SDL.h>



int Game::Init()
{
    if( SDL_Init(SDL_INIT_EVERYTHING ^ SDL_INIT_AUDIO))
    {
      printf("error Game::Init() -> SDL_Init()\n");
      return -1;
    }

    window = SDL_CreateWindow("SDL_CreateTexture",
                     SDL_WINDOWPOS_UNDEFINED,
                     SDL_WINDOWPOS_UNDEFINED,
                     500, 500,
                     SDL_WINDOW_RESIZABLE);
   
    scene = new Scene();
    
    return 0;
}

Game::~Game()
{
    delete scene;
}

void Game::Render()
{
    SDL_SetRenderDrawColor(render, 0xff, 0xFf, 0xFf, 0xFF);
    SDL_RenderClear(render);
    
    scene->Render();
   //        SDL_RenderCopy(render, Background_Tx, NULL, NULL);
   //
   //      //  Loading_Surf = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);
   //
   //        /* Filling the surface with red color. */
   //
    SDL_RenderPresent(render);
}



//void Game::Tick(<#float delta#>)
//{
//
//}

//void Game::Tick(<#float delta#>)
//{
//    
//}
void Game::Input()
{
    if(SDL_PollEvent(&event) )
    {
      if(event.type == SDL_QUIT)
          play = false;
    }
}

