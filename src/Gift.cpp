#include "Gift.h"
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//handle gift and random if good or bad
void Gift::handleCollision(Player& gameObject)
{
    srand(time(NULL));
    m_deleted = true;
    int lives, score;
   
    //randomizing gifts 
    switch (rand()%4+1) {

case gift_1:
         lives = gameObject.getlives();
        gameObject.setlives(++lives);
        Sounds_E::instance().get_Sounds(GIFT_SOUNDS, gift_life).play();
        //m_S_Buf[gift_life]->play();
        break;
        
    case gift_2:
        Sounds_E::instance().get_Sounds(GIFT_SOUNDS, gift_score).play();
         score = gameObject.getscore();
        gameObject.setscore(score+=2);
        break;
    case gift_3:
        Sounds_E::instance().get_Sounds(GIFT_SOUNDS, gift_enemy).play();
         m_Get_Enemy = true;
           break;
    case gift_4:
        Sounds_E::instance().get_Sounds(GIFT_SOUNDS, gift_time).play();
        m_Plus_Time = true;
        break;
};

}
//==========================================================

