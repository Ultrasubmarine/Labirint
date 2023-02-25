//
//  ResourceManager.hpp
//  Labirint
//
//  Created by marina porkhunova on 12.02.2023.
//

#ifndef ResourceManager_hpp
#define ResourceManager_hpp

#include <fstream>
#include <stdio.h>
#include <map>

#include "json.hpp"

#include "TextureLoader.hpp"
#include "FontLoader.hpp"
#include "JsonLoader.hpp"

#include "RenderSystem.hpp"

using json = nlohmann::json;

class ResourceManager
{
    TextureLoader* _textureLoader;
    FontLoader* _fontLoader;
    JsonLoader* _jsonLoader;
    
public:
    ResourceManager(RenderSystem* render);
    ~ResourceManager();
    
    Texture* GetTexture(std::string& title);
    Texture* GetFont(std::string& title);
    
    static const json* GetGameSettings();
    const json* GetScene(std::string& title);
    
   // char* GeneratePath(
};
#endif /* ResourceManager_hpp */
