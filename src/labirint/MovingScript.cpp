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
    t = GetComponent<Transform>(this->GetSid());
   // t = GET_COMPONENT(Transform, this->GetSid());
}

#include "Game.hpp"
#include "Time.hpp"
void MovingScript::Update(double deltaTime)
{
    
    int newX= pixel_speed * deltaTime * direct + t->GetPosition().x;
    t->SetPosition(newX, 50);

    if(t->GetPosition().x >= x_max && direct>0)
        direct = -1;
    else if(t->GetPosition().x <= x_min && direct<0)
        direct = 1;
    
}
