//
//  Render.cpp
//  Labirint
//
//  Created by marina porkhunova on 06.01.2023.
//

#include "Render.hpp"
#include "Transform.hpp"

void RenderSystem::Render(std::set<RenderObj*> renderObjects)
{  
    for(auto obj : renderObjects)
    {
        auto image = obj->sceneObj->GetImage();
        
        if(obj->sceneObj->GetTransform().IsDirty())
        {
            auto t = obj->sceneObj->GetTransform();
            auto p = t.GetPosition();

            obj->dstrect.x = p.x;
            obj->dstrect.y = p.y;
            obj->dstrect.w = image->GetRect().w * t.GetScale().x;
            obj->dstrect.h = image->GetRect().h * t.GetScale().y;
            
            t.ClearDirty();
        }
      
        SDL_RenderCopy(render, image->GetTexture(), &image->GetRect(), &obj->dstrect);
    }
}
