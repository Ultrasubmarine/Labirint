//
//  ResourceManager.hpp
//  Labirint
//
//  Created by marina porkhunova on 12.02.2023.
//

#ifndef ResourceManager_hpp
#define ResourceManager_hpp

#include <stdio.h>
#include <map>

#include "json.hpp"

#include "TextureLoader.hpp"
#include "RenderSystem.hpp"

using json = nlohmann::json;

class ResourceManager
{
    TextureLoader* _textureLoader;
    
public:
    ResourceManager(RenderSystem* render);
    ~ResourceManager();
    
    Texture* GetTexture(std::string& title);
    json GetScene(std::string& title);
};
#endif /* ResourceManager_hpp */
