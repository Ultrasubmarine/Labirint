//
//  Window.hpp
//  Labirint
//
//  Created by marina porkhunova on 18.02.2023.
//

#ifndef Window_hpp
#define Window_hpp

#include <SDL2/SDL.h>
#include <stdio.h>

#include "json.hpp"
using json = nlohmann::json;

class Window
{
    static const int DEFAULT_WIDTH = 600;
    static const int DEFAULT_HEIGHT = 600;
    static inline std::string const DEFAULT_TITLE = "[Default Title]";

    std::string _title;
    int _width, _height;
    SDL_Window* _window;
    
public:
    Window(const json* settings);
    ~Window();
    
    SDL_Window* GetWindow() const { return _window;};
    
private:
    void LoadSettings(const json* settings);
    inline void CreateWindow();
};
#endif /* Window_hpp */
