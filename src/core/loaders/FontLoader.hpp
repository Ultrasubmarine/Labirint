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

#include "TextTexture.hpp"

#define DEFAULT_FONT "Roboto-Light"

class FontLoader
{
    SDL_Renderer *_render;
    
    // TODO remove null ptrs
    std::unordered_map<std::string, std::weak_ptr<TTF_Font>> _fonts;

public:
    FontLoader(SDL_Renderer *render);
    ~FontLoader();
    
    /// doesn't storage; TODO is it okay? 
    std::shared_ptr<TextTexture> GetText(std::string& text, std::shared_ptr<TTF_Font> font, int fsize, SDL_Color color);
    
    std::shared_ptr<TTF_Font> GetFont(std::string& name);
    std::shared_ptr<TTF_Font> LoadFont(std::string& name, char *fullPath);
};


#endif /* FontLoader_hpp */
