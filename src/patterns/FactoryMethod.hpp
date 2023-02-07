//
//  FactoryMethod.hpp
//  Labirint
//
//  Created by marina porkhunova on 07.02.2023.
//

#ifndef FactoryMethod_hpp
#define FactoryMethod_hpp

#include <stdio.h>
#include <map>

template<typename Key, typename TBase, typename...TCreateMethodArgs>
class FactoryMethod
{
     using TCreateMethod = TBase*(*)(TCreateMethodArgs...);
    
public:
    
    bool Register(Key typeId, TCreateMethod createFunc);
    TBase* Create(Key typeId,TCreateMethodArgs... args);
    
private:
    std::map<Key, TCreateMethod> _creatorFuncs;
    
};

template<typename Key, typename TBase, typename...TCreateMethodArgs>
bool FactoryMethod<Key, TBase, TCreateMethodArgs...>::Register(Key k, TCreateMethod createFunc)
{
    if(_creatorFuncs.find(k) != _creatorFuncs.end())
        return false;
    
    _creatorFuncs[k] = createFunc;
    return true;
}

template<typename Key, typename TBase, typename...TCreateMethodArgs>
TBase* FactoryMethod<Key, TBase, TCreateMethodArgs...>::Create(Key k, TCreateMethodArgs... args)
{
    if(auto it = _creatorFuncs.find(k); it != _creatorFuncs.end())
    {
        return it->second(args...);
    }
    return nullptr;
}

// using TCreateComponent = Component*(*)(SId);
#endif /* FactoryMethod_hpp */
