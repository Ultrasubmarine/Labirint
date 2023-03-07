//
//  Game.cpp
//  
//
//  Created by marina porkhunova on 20.12.2022.
//
#include "ComponentSystem.hpp"
#include "Game.hpp"

#include <SDL2/SDL.h>

#include "json.hpp"
using json = nlohmann::json;

int Game::Init()
{
    const json* gameSettings = ResourceManager::GetGameSettings();
    
    window = new Window(gameSettings);
    if(!window->GetWindow())
        return -1;
    
    renderSystem = new RenderSystem(window->GetWindow());
    resourceManager = new ResourceManager(renderSystem);
    sceneManager = new SceneManager();
    debug = new DebugSystem();
    
    std::string s_name = (*gameSettings)["main_scene"].get<std::string>();
    sceneManager->LoadScene(s_name);
    return 0;
}


Game::~Game()
{
    delete debug;
    delete resourceManager;
    delete renderSystem;
    delete sceneManager;
    delete window;
}


void Game::Render()
{
    renderSystem->Render();
}

void Game::Tick(float delta_tick)
{
    ComponentSystem::UpdateComponents(delta_tick);
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

#include <thread>
void Game::Loop()
{
    time.FirstInitialization();
    
    Uint32 initial_ticks, elapsed_ms;
    while(play)
    {
        
        initial_ticks = SDL_GetTicks();

         //do things
        time.CalculateTime();
        Input();
        Tick(time.deltaTime);//TODO GET TIME
        
        debug->Update();
        
        Render();
        
        
        elapsed_ms = SDL_GetTicks() - initial_ticks;
        if(elapsed_ms < ms_frame)
            SDL_Delay(ms_frame - elapsed_ms);
    }
}

