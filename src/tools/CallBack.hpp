//
//  CallBack.hpp
//  Labirint
//
//  Created by marina porkhunova on 22.12.2022.
//

#ifndef CallBack_hpp
#define CallBack_hpp

#include <stdio.h>

#include <iostream>
#include <functional>
#include <forward_list>

using namespace std;

template<typename...Args>
class CallBack
{
    using f_type = void(*)(Args...);
    forward_list<f_type> _functions;
public:
    
    CallBack() = default;
    
    void Add(f_type func);
    void Remove(f_type func);
    void Call(Args...args);
    
};

template<typename...Args>
void CallBack<Args...>::Add(f_type func)
{
    _functions.push_front(func);
}

template<typename...Args>
void CallBack<Args...>::Remove(f_type func)
{
    _functions.remove(func);
}

template<typename...Args>
void CallBack<Args...>::Call(Args...args)
{
    for (auto f :_functions) {
        f(args...);
    }
}

template<>
class CallBack<void>
{
    using f_type = void(*)();
    forward_list<f_type> _functions;
public:
    
    CallBack() = default;
    
    void Add(f_type func) { _functions.push_front(func); };
    void Remove(f_type func) { _functions.remove(func); };
    
    void Call()
    {
        for (auto f :_functions) {
            f();
        }
    }
};

#endif /* CallBack_hpp */

