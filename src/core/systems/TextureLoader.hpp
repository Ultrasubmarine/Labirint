//
//  TextureLoader.hpp
//  Labirint
//
//  Created by marina porkhunova on 07.01.2023.
//

#ifndef TextureLoader_hpp
#define TextureLoader_hpp

#include <stdio.h>
#include <map>
#include <SDL2/SDL.h>

//TEMP PLACE
#include <cstdint>
#include <CoreFoundation/CoreFoundation.h>

class TextureLoader
{
    SDL_Renderer *_render;

    //const char *title ????? think about key type
    std::map<const char *, SDL_Texture *> _textures;

    SDL_Texture* LoadTexture(const char *title);
public:
    TextureLoader(SDL_Renderer *render);
    
    SDL_Texture* GetTexture(const char *title);
    
    ~TextureLoader();
};

char * GetPath(CFStringRef name, CFStringRef type);

#endif /* TextureLoader_hpp */
