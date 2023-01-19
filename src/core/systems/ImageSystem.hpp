//
//  ImageSystem.hpp
//  Labirint
//
//  Created by marina porkhunova on 19.01.2023.
//

#ifndef ImageSystem_hpp
#define ImageSystem_hpp

#include <stdio.h>
#include "Image.hpp"

// TODO
// it's slise between render and createComponent function.
// do I really need this sistem

class ImageSystem
{
    std::map<sid, Image*> _objects;

public:

    ~ImageSystem();
    
    Image* CreateImage(sid id);
    void DeleteImage(sid id);
    
    Image* GetImageBySID(sid id);
};
#endif /* ImageSystem_hpp */
