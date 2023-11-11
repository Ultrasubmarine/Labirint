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

enum class ResourceType
{
    texture,
    font,
    scene
};

class ResourceManager
{
    TextureLoader* _textureLoader;
    FontLoader* _fontLoader;
    JsonLoader* _jsonLoader;
    
    std::shared_ptr<Font> GetFont(std::string& name);
    
public:
    ResourceManager(RenderSystem* render);
    ~ResourceManager();
    
    std::shared_ptr<Texture> GetTexture(std::string& title);
    std::shared_ptr<TextTexture> GetTextTexture(std::string& text, std::string& fontName, int fsize, SDL_Color color);
    
    static const json* GetGameSettings();
    const json* GetSceneSettings(std::string& title);
    
    const char* GetResourcePath(ResourceType type, std::string& name, std::string format);
};
#endif /* ResourceManager_hpp */
