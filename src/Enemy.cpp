#include "Enemy.h"
#include "Player.h"

void Enemy:: handleCollision(Game_Object& gameObject) 
{
    if (&gameObject == this) return;
    // double dispatch
    gameObject.handleCollision(*this);
}

void Enemy::handleCollision(Player& gameObject)
{

}

void Enemy::handleCollision(Enemy& gameObject)
{
    // ignore
}

void Enemy::handleCollision(Gift& gameObject)
{
    // ignore
}

void Enemy::handleCollision(Money& gameObject)
{
    // ignore
}
void Enemy::handleCollision(Wall& gameObject)
{
    m_Elemnt_Of_Game.move(0, -m_Elemnt_Of_Game.getGlobalBounds().height / 3);
}