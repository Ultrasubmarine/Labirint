//
//  Game.cpp
//  
//
//  Created by marina porkhunova on 20.12.2022.
//

#include "Game.hpp"
#include "ComponentSystem.hpp"

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
    
    Load();
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


#include <fstream>
#include "json.hpp"
using json = nlohmann::json;

#include "CoreFunctions.hpp"
#include "GetPath_Apple.hpp"

void Game::Load()
{
    const char *path = GetPath_Apple(CFSTR("resources/game_settings"), CFSTR("json"));
    
    std::ifstream buff(path);
    json gameSettings = json::parse(buff);
    
    delete path;

    std::string path_1 ("resources/scenes/");
    path_1.append(gameSettings["main_scene"]);
    CFStringRef p = CFStringCreateWithCString(NULL, path_1.c_str(), NULL);
    
    
    const char *path2 =  GetPath_Apple(CFSTR("resources/scenes/test_scene"), CFSTR("json"));//GetPath(p, CFSTR("json")); // scene;
    
    
    std::ifstream sceneBuff(path2);
    json sceneSettings = json::parse(sceneBuff);
    
    for(auto hubs: sceneSettings["hubs"].array())
    {
       // js.get<std::string>();
        const char* n = hubs["name"].get<std::string>().c_str();
        std::list<TypeId> components{};
      //  CreateGameHub(const char* uniqueName, );
        auto o =  CreateGameHub(n, components) ;//hubs["name"]
    }
    
    
    //float my_p = data2["pi"];
}
