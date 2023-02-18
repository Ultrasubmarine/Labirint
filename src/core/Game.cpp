//
//  Game.cpp
//  
//
//  Created by marina porkhunova on 20.12.2022.
//

#include "Game.hpp"
#include "ComponentSystem.hpp"

#include <SDL2/SDL.h>

#include "json.hpp"
using json = nlohmann::json;

int Game::Init()
{

    if(!CreateWindow())
        return -1;

    renderSystem = new RenderSystem(window);
    resourceManager = new ResourceManager(renderSystem);
    sceneManager = new SceneManager();
    
    Load();
    return 0;
}


Game::~Game()
{
    delete resourceManager;
    delete renderSystem;
    
    SDL_DestroyWindow(window);
    SDL_Quit();
}

bool Game::CreateWindow()
{
    if( SDL_Init(SDL_INIT_EVERYTHING ^ SDL_INIT_AUDIO))
    {
      printf("error Game::Init() -> SDL_Init()\n");
      return -1;
    }
    
    const char* title;
    int width, height;
    
    const json* settings = ResourceManager::GetGameSettings();
    if(settings)
    {
        title = (*settings)["name"].get<std::string>().c_str();
        width =(*settings)["screen"]["width"].get<int>();
        height =(*settings)["screen"]["height"].get<int>();
    }
    
    window = SDL_CreateWindow(title,
                     SDL_WINDOWPOS_UNDEFINED,
                     SDL_WINDOWPOS_UNDEFINED,
                     width, height,
                     SDL_WINDOW_RESIZABLE);
    
    if(!window)
    {
        printf("error: fail creating window \n");
        return false;
    }
    return true;
}

void Game::Render()
{
    renderSystem->Render();
}

void Game::Tick(float delta_tick)
{
    ComponentSystem::UpdateComponents();
   // scene->Tick(delta_tick);
}

void Game::Input()
{
    if(SDL_PollEvent(&event) )
    {
        if(event.type == SDL_QUIT)
            play = false;
        
        if(event.type == SDL_MOUSEMOTION)
        {
       //     scene->GetFirstObj()->GetTransform().SetPosition(event.motion.x, event.motion.y);
        }
        else if(event.type == SDL_KEYDOWN)
        {
            if(event.key.keysym.sym == SDLK_s)
            {
                auto s = std::string("scene2");
                sceneManager->LoadScene(s);
            }
        }
    }
}

void Game::Loop()
{
    while(play)
    {
        Input();
        Tick(0.5f);//TODO GET TIME
        Render();
    }
}

void Game::Load()
{
    const json* gameSettings = ResourceManager::GetGameSettings();
    if(!gameSettings)
    {
        printf("error: Game::Load() fail load gameSetting \n");
        return;
    }
    std::string s_name = (*gameSettings)["main_scene"].get<std::string>();
    
    sceneManager->LoadScene(s_name);
}
