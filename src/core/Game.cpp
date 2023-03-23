//
//  Game.cpp
//  
//
//  Created by marina porkhunova on 20.12.2022.
//
#include "ComponentSystem.hpp"
#include "Game.hpp"

#include "json.hpp"
#include "Debug.h"

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
    
    frameRate.SetFixedFrame(60);
    
    std::string s_name = (*gameSettings)["main_scene"].get<std::string>();
    sceneManager->LoadScene(s_name);
    
    return 0;
}

void Game::Destroy()
{
    delete sceneManager;
}

Game::~Game()
{    
    delete debug;
    delete resourceManager;
    delete renderSystem; 
    delete window;
}

void Game::Render()
{
    renderSystem->Render();
    debug->Render(renderSystem->GetRenderer());
    renderSystem->Present();
}

void Game::Update(float delta_tick)
{
    ComponentSystem::UpdateComponents(delta_tick);
    debug->Update();
}

#include <SDL2/SDL.h>
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
    frameRate.FirstInitialization();
    
    LOG("first initialization " + std::to_string(6) + " end");
    while(play)
    {
        Input();
        Update(frameRate.GetDeltaTime() * timeScale);
        Render();
        
        frameRate.WaitFrame();
    }
}
