#include "Gift.h"

void Gift::handleCollision(Player& gameObject)
{
    m_deleted = true;
    int lives, score;
    srand(time(NULL));
    //randomizing gifts 
    switch ((rand() % 3) + 1) {
    case gift_1:
         lives = gameObject.getlives();
        gameObject.setlives(++lives);
        break;

    case gift_2:
         score = gameObject.getscore();
        gameObject.setscore(score+=2);
        break;
    case gift_3:
         m_Get_Enemy = true;
           break;
};

}