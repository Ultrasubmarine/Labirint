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
#include "DebugSystem.hpp"
#include "FrameRate.hpp"

class Game : public Singleton<Game>
{
    bool play = true;
    float timeScale = 1.0f;
    
    void Input();
    void Update(float deltaTime);
    void Render();
    
    
public:

    SDL_Event event;
    
    Window *window;
    RenderSystem *renderSystem;
    ResourceManager *resourceManager;
    SceneManager *sceneManager;
    DebugSystem *debug;
    
    FrameRate frameRate;
    
    ~Game();
    
    int Init();
    void Loop();
    void Destroy();
};

#endif /* Game_hpp */
