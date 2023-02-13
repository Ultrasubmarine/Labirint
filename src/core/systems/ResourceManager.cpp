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
}

ResourceManager::~ResourceManager()
{
    delete _textureLoader;
}


Texture* ResourceManager::GetTexture(std::string& title)
{
    std::string r_path ="resources/images/" + title;
    std::string type = "bmp";
    
    char *image_path = GetPath(r_path, type);
    auto t = _textureLoader->GetTexture(title, image_path);
    delete image_path;
    
    return t;
}
