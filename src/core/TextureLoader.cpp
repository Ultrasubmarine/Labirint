//
//  TextureLoader.cpp
//  Labirint
//
//  Created by marina porkhunova on 07.01.2023.
//

#include "TextureLoader.hpp"

#include <string>
#include <iostream>


//TEMP PLACE
#include <cstdint>
#include <CoreFoundation/CoreFoundation.h>

//use free() to returned string
char * GetPath(CFStringRef name, CFStringRef type)
{
#ifdef __APPLE__
    CFURLRef manifest_url = CFBundleCopyResourceURL(CFBundleGetMainBundle(),
                                                    name, type,
                                                    NULL);
    char * manifest_path = (char *)malloc(PATH_MAX);
    CFURLGetFileSystemRepresentation(manifest_url, true, (uint8_t *)manifest_path, PATH_MAX);
    
    if (manifest_url != NULL)
        {
          CFRelease(manifest_url);
        }
    return manifest_path;
#endif
    return NULL;
}
//// END TEMP PLASE

TextureLoader::TextureLoader(SDL_Renderer *render)
{
    _render = render;
}

SDL_Texture* TextureLoader::GetTexture(const char *title)
{
    if(_textures.contains(title))
        return _textures[title];
    
    return LoadTexture(title);
}

SDL_Texture* TextureLoader::LoadTexture(const char *title)
{
    char *image_path = GetPath(CFSTR("resources/images/frog"), CFSTR("bmp"));

    SDL_Surface *bmpSurf = SDL_LoadBMP(image_path);
    free(image_path);
    
    SDL_Texture *bmpTex = SDL_CreateTextureFromSurface(_render, bmpSurf);
    SDL_FreeSurface(bmpSurf);
    
    if(bmpTex)
        return _textures[title] = bmpTex;
    
    std::cout<<"error: TextureLoader::LoadTexture() texture:"<<title;
    return NULL;
}


TextureLoader::~TextureLoader()
{
    for(auto t : _textures)
    {
        SDL_DestroyTexture(t.second);
    }
    _textures.clear();
}

