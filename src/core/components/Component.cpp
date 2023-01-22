//
//  component.cpp
//  Labirint
//
//  Created by marina porkhunova on 19.01.2023.
//

#include "Component.hpp"

Component::Component(sid id)
{
    _sid = id;
}


const sid Component::GetSid()
{
    return _sid;
};



