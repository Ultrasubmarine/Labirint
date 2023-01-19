//
//  ComponentFactory.cpp
//  Labirint
//
//  Created by marina porkhunova on 19.01.2023.
//

#include "ComponentFactory.hpp"

#include "Game.hpp"
#include "RenderSystem.hpp"
#include "TransformSystem.hpp"

Component* CreateComponent(sid id, ComponentType type)
{
    Component* c;
    
    switch (type) {
        case ComponentType::Transform:
        {
            c = Game::Instance().transformSystem->CreateTransform(id);
            break;
        }
        case ComponentType::Image:
        {
            c = Game::Instance().imageSystem->CreateImage(id);
            break;
        }     
        default:
            break;
    }
    
    return c;
}
