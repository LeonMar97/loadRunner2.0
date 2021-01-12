#include "Gift.h"

void Gift::handleCollision(Player& gameObject)
{
    m_deleted = true;
    int lives =gameObject.getlives();
    lives++;
    gameObject.setlives(lives);
}