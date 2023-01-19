//
//  TransformSystem.hpp
//  Labirint
//
//  Created by marina porkhunova on 19.01.2023.
//

#ifndef TransformSystem_hpp
#define TransformSystem_hpp

#include <stdio.h>

#include "StringID.hpp"
#include "Transform.hpp"


class TransformSystem
{
    std::map<sid, Transform*> _objects;
    //TODO tree

public:

    ~TransformSystem();
    
    Transform* CreateTransform(sid id);
    void DeleteTransform(sid id);
    
    Transform* GetTransformBySID(sid id);
};

#endif /* TransformSystem_hpp */
