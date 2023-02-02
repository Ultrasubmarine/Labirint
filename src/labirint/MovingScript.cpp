//
//  MovingScript.cpp
//  Labirint
//
//  Created by marina porkhunova on 28.01.2023.
//

#include "MovingScript.hpp"
#include "ComponentSystem.hpp"


#include "ComponentFactory.hpp"
REGISTER_COMPONENT_CPP(MovingScript)
//
//MovingScript::MovingScript(sid id): Script(id)
//{
//    Init();
//}

void MovingScript::Init()
{
    t = GetComponent<Transform>(this->GetSid());
}

void MovingScript::Update()
{
    // it's disgusting and i know it. just test
    if( direct>0 && direct + t->GetPosition().x <= x_max)
        t->SetPosition(direct + t->GetPosition().x, 50);
    else if( direct<1 && direct + t->GetPosition().x >= x_min)
        t->SetPosition(direct + t->GetPosition().x, 50);
    else
        direct *= (-1);
}
