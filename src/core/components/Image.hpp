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

#include "Component.hpp"

#include <typeinfo>
#include <typeindex>


class Image : public Component
{
    REGISTER_COMPONENT_H(Image)
    
private:
    SDL_Texture* _texture;
    SDL_Rect _srcrect;
    
    uint _layer;
    
    bool _dirty;
public:
    
    Image(sid id) :Component(id){};
    ~Image();
    
    void SetTexture(SDL_Texture *texture, SDL_Rect* srcrect = NULL);
    
    SDL_Texture* GetTexture();
    const SDL_Rect& GetRect();
    
    bool IsDirty();
    void ClearDirty();
};


#endif /* Image_hpp */
