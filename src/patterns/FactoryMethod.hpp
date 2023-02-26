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
    std::map<TKey,TBase*(*)(TCreateMethodArgs...)>& TheMap();
    
};

template<typename Key, typename TBase, typename...TCreateMethodArgs>
bool FactoryMethod<Key, TBase, TCreateMethodArgs...>::Register(Key k, TCreateMethod createFunc)
{
    if(TheMap().find(k) != TheMap().end())
        return false;
    
    TheMap()[k] = createFunc;
    return true;
}

template<typename Key, typename TBase, typename...TCreateMethodArgs>
TBase* FactoryMethod<Key, TBase, TCreateMethodArgs...>::Create(Key k, TCreateMethodArgs... args)
{
    if(auto it = TheMap().find(k); it != TheMap().end())
    {
        return it->second(args...);
    }
 
    return nullptr;
}

template<typename Key, typename TBase, typename...TCreateMethodArgs>
std::map<Key, TBase*(*)(TCreateMethodArgs...)>& FactoryMethod<Key, TBase, TCreateMethodArgs...>::TheMap()
{
    static std::map<Key, TBase*(*)(TCreateMethodArgs...)> _creators{};
    return _creators;
}

#endif /* FactoryMethod_hpp */
