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
#include "Scene.hpp"
#include "RenderSystem.hpp"

#include "TextureLoader.hpp"
#include "ResourceManager.hpp"

class Game : public Singleton<Game>
{
    bool play = true;
    
    void Input();
    void Tick(float delta_tick);
    void Render();
    
public:

    SDL_Event event;
    SDL_Window *window;
    

    RenderSystem *renderSystem;
    Scene* scene;
    ResourceManager *resourceManager;
    
    ~Game();
    
    int Init();
    void Loop();

    //test
    void TestSceneObj();
    
    void Load();
};

#endif /* Game_hpp */
