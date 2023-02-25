//
//  Text.cpp
//  Labirint
//
//  Created by marina porkhunova on 25.02.2023.
//

#include "Text.hpp"
#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>


void Text::SetText(std::string& t)
{
// FontLoader
    TTF_Font* Sans = TTF_OpenFont("Sans.ttf", 24);
    
    SDL_Surface* surfaceText = TTF_RenderText_Solid(Sans,t.c_str(), Color);
//
//    // now you can convert it into a texture
    SDL_Texture* Text_texture = SDL_CreateTextureFromSurface(renderer, surfaceText);
    
    SDL_FreeSurface(surfaceText);
    
    auto txt =   Game::Instance().resourceManager->GetTexture(tx_name);
//
//    
//    // as TTF_RenderText_Solid could only be used on
//    // SDL_Surface then you have to create the surface first
//    SDL_Surface* surfaceMessage =
//        TTF_RenderText_Solid(Sans, "put your text here", White);
    
}
