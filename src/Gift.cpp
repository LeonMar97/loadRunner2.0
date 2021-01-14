#include "Gift.h"

void Gift::handleCollision(Player& gameObject)
{
    
    m_deleted = true;
    int lives, score;
    srand(time(NULL));
    //randomizing gifts 
    switch ((rand() % 4) + 1) {

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
/*setting player sounds..
void Gift::set_Sounds() {
    
    std::vector<std::string>names = {"GENERIC_THANKS_02.wav","GAME_WIN_SELF_01.wav",
                                    "ARRESTED_DRUNK_03.wav",
                                    "BASEJUMP_ABOUT_TO_JUMP_03.wav" };
                                    
    int j;
    sf::SoundBuffer* sd;//sound
    sf::Sound* sound ;
    for (j = 0; j < names.size(); j++) {
        sound = new sf::Sound;
        sd = new sf::SoundBuffer;
        if (!sd->loadFromFile(names[j])) {
            std::cout << "couldnt load//"<<names[j]<<std::endl;
        }
        sound->setBuffer(*sd);
        m_S_Buf.push_back(sound);
    }
    

}
*/


//===========================================================
/*
 "GAME_WIN_SELF_01.wav",
                                    "ARRESTED_DRUNK_03.wav",
                                    "BASEJUMP_ABOUT_TO_JUMP_03.wav"*/