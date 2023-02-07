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
protected:
    Singleton(){};
public:
    Singleton(Singleton const &) = delete;
    void operator=(Singleton const &) = delete;
    
    static T& Instance()
    {
        static T instance;
        return instance;
    }
};
#endif /* Singleton_hpp */
