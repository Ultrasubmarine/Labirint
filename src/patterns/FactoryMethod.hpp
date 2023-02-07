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
/// Facroty
/// @arg TKey - me
template<typename TKey, typename TBase, typename...TCreateMethodArgs>
class FactoryMethod
{
     using TCreateMethod = TBase*(*)(TCreateMethodArgs...);
public:
    
    bool Register(TKey k, TCreateMethod createFunc);
    TBase* Create(TKey k,TCreateMethodArgs... args);
    
private:
    std::map<TKey, TCreateMethod> _creators;
    
};

template<typename Key, typename TBase, typename...TCreateMethodArgs>
bool FactoryMethod<Key, TBase, TCreateMethodArgs...>::Register(Key k, TCreateMethod createFunc)
{
    if(_creators.find(k) != _creators.end())
        return false;
    
    _creators[k] = createFunc;
    return true;
}

template<typename Key, typename TBase, typename...TCreateMethodArgs>
TBase* FactoryMethod<Key, TBase, TCreateMethodArgs...>::Create(Key k, TCreateMethodArgs... args)
{
    if(auto it = _creators.find(k); it != _creators.end())
    {
        return it->second(args...);
    }
    return nullptr;
}

#endif /* FactoryMethod_hpp */
