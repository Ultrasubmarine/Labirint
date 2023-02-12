//
//  ResourceManager.hpp
//  Labirint
//
//  Created by marina porkhunova on 12.02.2023.
//

#ifndef ResourceManager_hpp
#define ResourceManager_hpp

#include <SDL2/SDL.h>

#include <stdio.h>
#include <map>


class ResourceManager
{
    std::map<char *, SDL_Texture *> _textures;
    
};
#endif /* ResourceManager_hpp */
