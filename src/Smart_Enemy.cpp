#include "Smart_Enemy.h"

//alguritem for smart enemy to fond player
void Smart_Enemy::effect(void* PlayerLoction, std::vector<Game_Object*>m_All_Objects[NUM_OF_OBJECTS])
{
    bool move = false;
    sf::Vector2f player_loc(*(sf::Vector2f*)PlayerLoction);
    auto deltaTime = m_clock.restart();
    float size = (m_Elemnt_Of_Game.getTexture()->getSize().x) / 3;
    sf::RectangleShape temp(m_Elemnt_Of_Game);
    if (What_In_Loc(m_Elemnt_Of_Game, m_All_Objects) == ladder &&
        (player_loc.y - this->get_loction().y > 0.1f || this->get_loction().y - player_loc.y > 0.1f))
    {

       sf::Vector2f next_move(up_down(player_loc, m_Elemnt_Of_Game.getPosition()));
        temp.move(next_move* size * deltaTime.asSeconds());
        if (What_In_Loc(temp, m_All_Objects) != wall) {
           
            this->move_Object(next_move , deltaTime, m_All_Objects);
            m_is_Wall = false;
            move = true;
        }
    }
    if (!move)
    {
        if ((What_In_Loc(m_Elemnt_Of_Game, m_All_Objects) == pole))
        {
            if ((player_loc.y - this->get_loction().y > 1.5f)) {
                sf::Vector2f next_move(0, 1);
           
                temp.move(next_move * size * deltaTime.asSeconds());
                Moving_Object::check_pole(m_All_Objects, *this, temp);
                if (What_In_Loc(temp, m_All_Objects) != wall) {
                    this->move_Object(next_move, deltaTime, m_All_Objects);
                    m_is_Wall = false;
                    move = true;
                }
            }
         
        }

        if (!move) {

            sf::RectangleShape temp(m_Elemnt_Of_Game);
            sf::Vector2f dir(right_left(player_loc, m_Elemnt_Of_Game.getPosition()));
            
            if (m_is_Wall) {
                dir.x *= -1;

            }
            temp.move(dir * size * deltaTime.asSeconds());
            
            if (What_In_Loc(temp, m_All_Objects) == wall)
            {
                m_is_Wall = !m_is_Wall;

            }
       
          
            this->move_Object(dir, deltaTime, m_All_Objects);

        }



    }
}
//==============================================================================
sf::Vector2f Smart_Enemy::up_down(sf::Vector2f player_loc, sf::Vector2f my_loc) {
    if (player_loc.y - my_loc.y>0.1f)
        return { 0,1 };
    else
        return { 0,-1 };
}
//============================================================================
sf::Vector2f Smart_Enemy::right_left(sf::Vector2f player_loc, sf::Vector2f my_loc) {
    if (player_loc.x - my_loc.x >= 0.1f)
            return { 1,0 };
        else
            return { -1,0 };
    
       
}
