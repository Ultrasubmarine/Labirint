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

class Image : public Component
{
    COMPONENT_BODY(Image)
    
private:
    Texture *_texture;
  //  SDL_Texture* _texture;
    SDL_Rect _srcrect;
    
    uint _layer;
    
    bool _dirty;
public:
    
    void SetTexture(Texture *texture, SDL_Rect* srcrect = NULL);
    
    SDL_Texture* GetTexture();
    const SDL_Rect& GetRect();
    
    bool IsDirty();
    void ClearDirty();
};


#endif /* Image_hpp */
