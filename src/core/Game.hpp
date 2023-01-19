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
#include "TransformSystem.hpp"
#include "ImageSystem.hpp"

#include "TextureLoader.hpp"

class Game : public Singleton<Game>
{
    bool play = true;
    
    void Input();
    void Tick(float delta_tick);
    void Render();
    
public:

    SDL_Event event;
    SDL_Window *window;
    
    
    TransformSystem *transformSystem;
    RenderSystem *renderSystem;
    ImageSystem *imageSystem;
    Scene* scene;
    TextureLoader *textureLoader;
    
    ~Game();
    
    int Init();
    void Loop();

    //test
    void TestSceneObj();
};

#endif /* Game_hpp */
