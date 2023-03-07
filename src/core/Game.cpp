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
    
    
    auto  rate = 60ll;
    fixedFrame_nanosec = std::chrono::seconds(1) ;
    fixedFrame_nanosec /= rate;
    
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
    
    
    std::chrono::nanoseconds delta = std::chrono::nanoseconds::zero();

    std::chrono::time_point<std::chrono::steady_clock> last_clock;// = std::chrono::high_resolution_clock::now();
    std::chrono::time_point<std::chrono::steady_clock> now_clock = std::chrono::steady_clock::now();
    
    while(play)
    {
         //do things
        time.CalculateNewFrameTime();
        
        Input();
        Tick(delta.count()/ static_cast<float>(std::nano::den));//time.GetDeltaTime());//TODO GET TIME
        
        debug->Update();
        
        Render();
        
        
     //   last_clock = now_clock;
        now_clock = std::chrono::steady_clock::now();
        delta = now_clock - last_clock;
        
        auto wait = fixedFrame_nanosec - delta;
        delta += wait;
        
        if( wait > std::chrono::nanoseconds::zero())
        {
            std::this_thread::sleep_for(wait);
            std::cout<<"wait:"<< (wait).count()<<endl;
        }
        
        last_clock = std::chrono::steady_clock::now();
        //WaitFixedRate();
         //   SDL_Delay(ms_frame - elapsedTime.count());
    }
}



void Game::WaitFixedRate()
{    
    auto elapsed_nanosec = time.GetElapsedTime();
    if( elapsed_nanosec < fixedFrame_nanosec)
        std::this_thread::sleep_for( fixedFrame_nanosec - elapsed_nanosec);
    
    
  
 //   auto f = std::chrono::duration<double, std::chrono::nanoseconds>(fixedFrame_nanosec - elapsed_nanosec);
    std::cout<<"wait:"<<  ( fixedFrame_nanosec - elapsed_nanosec).count()<<endl;
}
