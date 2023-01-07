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
    
    if(!window)
    {
        printf("error: fail creating window \n");
        return -1;
    }
    
    scene = new Scene();
    renderSystem = new RenderSystem(window);
    textureLoader = new TextureLoader(renderSystem->GetRenderer());
    
    return 0;
}

Game::~Game()
{
    delete renderSystem;
    delete scene;
    delete textureLoader;
    
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Game::Render()
{
    renderSystem->Render();
}

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

