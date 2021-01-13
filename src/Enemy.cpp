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
    // call the player so it can decrease its own live count
    gameObject.handleCollision(*this);
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