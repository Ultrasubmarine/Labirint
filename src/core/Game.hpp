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

#include "Scene.hpp"
class Game
{
    
    static Game* single;
public:
//    Game() = default;
//
//    Game& operator= (const Game& ) = delete;
//    Game(const Game& ) = delete;
//
//
    
    int Init();
    
    void Input();
    void Tick(float delta);
    void Render();
//
//    bool play = true;
    
    
    
    SDL_Event event;
    SDL_Window *window;
    SDL_Renderer *render;
    bool _dirtyRender = false;
    
    bool play = true;
    
    
    Scene* scene;
    
public:
    ~Game();
};

#endif /* Game_hpp */
