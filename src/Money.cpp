#pragma once
#include "Money.h"

void Money::handleCollision(Game_Object& gameObject) 
{
    if (&gameObject == this) return;
    // double dispatch
    gameObject.handleCollision(*this);
}

void Money::handleCollision(Player& gameObject)
{
    m_deleted = true;
    gameObject.handleCollision(*this);
}

void Money::handleCollision(Enemy& gameObject)
{
    //  ignore
}

void Money::handleCollision(Money& gameObject)
{
    //ignore
}
