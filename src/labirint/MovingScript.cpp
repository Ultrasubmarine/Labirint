//
//  MovingScript.cpp
//  Labirint
//
//  Created by marina porkhunova on 28.01.2023.
//

#include "MovingScript.hpp"

COMPONENT_CPP(MovingScript)
//
//MovingScript::MovingScript(sid id): Script(id)
//{
//    Init();
//}
#include "CoreFunctions.hpp"
void MovingScript::Init()
{
    t = GetComponent2<Transform>(this->GetSid(), TYPE_ID(Transform));
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
