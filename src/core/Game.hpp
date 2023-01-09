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
#include "Render.hpp"
#include "TextureLoader.hpp"

class Game : public Singleton<Game>
{
   // Game():Singleton(){};
    //
    //    Game& operator= (const Game& ) = delete;
    //    Game(const Game& ) = delete;
    //
    //
public:

    int Init();
    
    void Input();
    void Tick(float delta_tick);
    void Render();

    SDL_Event event;
    SDL_Window *window;
    
    RenderSystem *renderSystem;
    Scene* scene;
    TextureLoader *textureLoader;
    
    
    bool play = true;

    ~Game();
    
    //test
    void TestSceneObj();
    
 //   Scene* GetScene() {return scene;};
};

#endif /* Game_hpp */
