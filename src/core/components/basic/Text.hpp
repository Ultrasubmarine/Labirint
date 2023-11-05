//
//  Text.hpp
//  Labirint
//
//  Created by marina porkhunova on 25.02.2023.
//

#ifndef Text_hpp
#define Text_hpp

#include <stdio.h>

#include "TextTexture.hpp"
#include "Component.hpp"
#include "Transform.hpp"

#include <SDL2/SDL.h>
#include <string>
#include <memory>

class Text: public Component
{
    COMPONENT_BODY(Text)
    
//  std::string text;
    std::shared_ptr<TextTexture> _texture;
    SDL_Rect _srcrect;

    void SetTexture(std::shared_ptr<TextTexture> texture, SDL_Rect* srcrect = NULL);
    bool _dirty;
    
    SDL_Rect *dst;
    Transform* transform;
    
    void Init() override;
public:

    void Render();    
    void Serialize(json &j) override;
    void Deserialize(json &j) override;
  
    void Draw(SDL_Renderer* render) override;
    
    SDL_Texture* GetTexture();
    const SDL_Rect& GetRect();
    
    bool IsDirty();
    void ClearDirty();
};

#endif /* Text_hpp */
