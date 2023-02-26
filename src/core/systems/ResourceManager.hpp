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
    
    
  //  std::shared_ptr<TTF_Font> GetFont(std::string& name);
    
public:
    ResourceManager(RenderSystem* render);
    ~ResourceManager();
    
    Texture* GetTexture(std::string& title);
 //   std::shared_ptr<TextTexture> GetTextTexture(std::string& text, std::string& fontName, int fsize);
    
    static const json* GetGameSettings();
    const json* GetScene(std::string& title);
    
   // char* GeneratePath(
};
#endif /* ResourceManager_hpp */
