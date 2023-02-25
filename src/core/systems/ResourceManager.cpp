//
//  ResourceManager.cpp
//  Labirint
//
//  Created by marina porkhunova on 12.02.2023.
//

#include "ResourceManager.hpp"
#include "GetPath_Apple.hpp"

ResourceManager::ResourceManager(RenderSystem* renderSystem)
{
    _textureLoader = new TextureLoader(renderSystem->GetRenderer());
    _fontLoader = new FontLoader(renderSystem->GetRenderer());
    _jsonLoader = new JsonLoader();
}

ResourceManager::~ResourceManager()
{
    delete _textureLoader;
    delete _fontLoader;
    delete _jsonLoader;
}

Texture* ResourceManager::GetTexture(std::string& title)
{
    Texture* t = _textureLoader->GetTexture(title);
    if(t)
        return t;
    
    std::string r_path ="resources/images/" + title;
    std::string type = "bmp";
    
    char *image_path = GetPath(r_path, type);
    t = _textureLoader->LoadTexture(title, image_path);
    delete image_path;
    
    return t;
}

Texture* ResourceManager::GetFont(std::string& title)
{
    Texture* t = _textureLoader->GetTexture(title);
    if(t)
        return t;
    
    std::string r_path ="resources/images/" + title;
    std::string type = "bmp";
    
    char *image_path = GetPath(r_path, type);
    t = _textureLoader->LoadTexture(title, image_path);
    delete image_path;
    
    return t;
    
}
const json* ResourceManager::GetGameSettings()
{
    auto j = JsonLoader::GetGameSettings();
    if(j)
        return j;
    
    std::string r_path ="resources/game_settings";
    std::string type = "json";
    
    char *json_path = GetPath(r_path, type);
    j = JsonLoader::LoadGameSettings(json_path);
    delete json_path;
    
    return j;
}

const json* ResourceManager::GetScene(std::string& title)
{
    std::string r_path ="resources/scenes/" + title;
    std::string type = "json";
    
    char *json_path = GetPath(r_path, type);
    
    if(*json_path == '\0')
    {
        cout<<"error: ResourceManager::GetScene() scene (" <<title<<") didn't found"<<endl;
        return nullptr;
    }
    
    auto j =   _jsonLoader->GetJson(json_path);
    delete json_path;
    
    return j;
}
