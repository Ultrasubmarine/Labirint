//
//  SceneManager.hpp
//  Labirint
//
//  Created by marina porkhunova on 18.02.2023.
//

#ifndef SceneManager_hpp
#define SceneManager_hpp

#include <stdio.h>
#include "Scene.hpp"

class SceneManager
{
    Scene* currentScene;
    
    void DestroyCurrentScene();
public:
    
    Scene* LoadScene(std::string& sceneName);
    Scene* GetCurrentScene();
};

#endif /* SceneManager_hpp */
