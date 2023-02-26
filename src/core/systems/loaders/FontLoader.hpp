//
//  FontLoader.hpp
//  Labirint
//
//  Created by marina porkhunova on 25.02.2023.
//

#ifndef FontLoader_hpp
#define FontLoader_hpp

//#include <SDL2/SDL.h>
//#include <SDL2_ttf/SDL_ttf.h>

#include <memory>
#include <stdio.h>
#include <map>



#include "TextTexture.hpp"

class FontLoader
{
    SDL_Renderer *_render;

    // TODO hash + unordered map & smart_ptr
 //   std::map<std::string, TextTexture*> _textTextures;
    std::map<std::string, std::weak_ptr<TTF_Font>> _fonts;

public:
    FontLoader(SDL_Renderer *render);
    ~FontLoader();
    
    /// doesn't storage; TODO is it okay? 
    std::shared_ptr<TextTexture> GetText(std::string& text, std::shared_ptr<TTF_Font> font, int fsize);
    
    std::shared_ptr<TTF_Font> GetFont(std::string& name);
    std::shared_ptr<TTF_Font> LoadFont(std::string& name, char *fullPath);
};


void DeleteTTF_Font(TTF_Font* t)
{
    TTF_CloseFont(t);
}
#endif /* FontLoader_hpp */
