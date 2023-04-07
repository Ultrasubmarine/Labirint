//
//  Font.h
//  Labirint
//
//  Created by marina porkhunova on 07.04.2023.
//

#ifndef Font_h
#define Font_h

#include <string>
#include <SDL2_ttf/SDL_ttf.h>

struct Font
{
    std::string name;
    
    TTF_Font *font;

    ~Font()
    {
        TTF_CloseFont(font);
    }
};

#endif /* Font_h */
