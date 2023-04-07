//
//  FontLoader.hpp
//  Labirint
//
//  Created by marina porkhunova on 25.02.2023.
//

#ifndef FontLoader_hpp
#define FontLoader_hpp

#include <stdio.h>
#include <unordered_map>

#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>

#include "Font.h"
#include "TextTexture.hpp"

#define DEFAULT_FONT "Roboto-Light"


class FontLoader
{
    SDL_Renderer *_render;
    
    std::unordered_map<std::string, std::weak_ptr<Font>> _fonts;

    void DeleteFont(Font* font);
    
public:
    FontLoader(SDL_Renderer *render);
    ~FontLoader();
    
    /// doesn't storage
    std::shared_ptr<TextTexture> GetText(std::string& text, std::shared_ptr<Font> font, int fsize, SDL_Color color);
    
    std::shared_ptr<Font> GetFont(std::string& name);
    std::shared_ptr<Font> LoadFont(std::string& name, char *fullPath);
};


#endif /* FontLoader_hpp */
