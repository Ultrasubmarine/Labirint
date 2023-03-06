//
//  Image.hpp
//  Labirint
//
//  Created by marina porkhunova on 06.01.2023.
//

#ifndef Image_hpp
#define Image_hpp

#include <stdio.h>
#include <SDL2/SDL.h>

#include "Texture.hpp"
#include "Component.hpp"
#include "Transform.hpp"

class Image : public Component
{
    COMPONENT_BODY(Image)
    
private:
    std::shared_ptr<Texture> _texture;
    SDL_Rect *dst;
    Transform* transform;
    
    uint _layer;
    
    bool _dirty;
    void Init() override;
public:
    
    void SetTexture(std::shared_ptr<Texture> texture, SDL_Rect* srcrect = NULL);
    
    SDL_Texture* GetTexture();
    const SDL_Rect& GetRect();
    
    bool IsDirty();
    void ClearDirty();
    
    void Draw(SDL_Renderer* render) override;
    
    void Serialize(json &j) override;
    void Deserialize(json &j) override;
};


#endif /* Image_hpp */
