//
//  Singleton.hpp
//  Labirint
//
//  Created by marina porkhunova on 07.01.2023.
//

#ifndef Singleton_hpp
#define Singleton_hpp

#include <stdio.h>

template<typename T>
class Singleton
{
    static T *_instance;
    Singleton();
public:
    T* GetInstance();
    
};
#endif /* Singleton_hpp */
