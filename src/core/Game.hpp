//
//  Game.hpp
//  
//
//  Created by marina porkhunova on 20.12.2022.
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include <SDL2/SDL.h>

#include "Singleton.hpp"

#include "Window.hpp"
#include "RenderSystem.hpp"
#include "ResourceManager.hpp"
#include "SceneManager.hpp"
#include "Time.hpp"

class Game : public Singleton<Game>
{
    bool play = true;
    
    void Input();
    void Tick(float delta_tick);
    void Render();
    
public:

    SDL_Event event;
    
    Window *window;
    RenderSystem *renderSystem;
    ResourceManager *resourceManager;
    SceneManager *sceneManager;
    Time time;
    
    ~Game();
    
    int Init();
    void Loop();
};

#endif /* Game_hpp */
