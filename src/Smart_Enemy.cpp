#include "Smart_Enemy.h"


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
           // next_move *= 0.9f;
            this->move_Object(next_move , deltaTime, m_All_Objects);
            m_is_Wall = false;
            move = true;
        }
    }
    if (!move)
    {
        if ((What_In_Loc(m_Elemnt_Of_Game, m_All_Objects) == pole))
        {
            if ((player_loc.y - this->get_loction().y > 0.1f)) {
                sf::Vector2f next_move(0, 1);
               // next_move *= 0.9f;
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
            //dir *= 0.9f;
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
   //    if( player_loc.y - my_loc.y <= 0.1f)
            return { 1,0 };
        else
            return { -1,0 };
    
       
}

/*

bool Move::getmovement_enemy(Location main_player) {
    // bool c;
    int movement;
    bool moved = false;
    if (main_player.row != m_current_location.row)
        if ((m_board->char_in_loc(m_current_location) == 'H')) {
            send_value(up_down(main_player, m_current_location));
            m_is_wall = false;
            moved = 1;
        }
    if (!(moved)) {
        movement = right_left(main_player, m_current_location);
        if (m_is_wall)
        {
            make_second(movement);
            send_value(movement);
        }
        else
            send_value(movement);
    }
    return true;
}
void Move::make_second(int& move)
{
    if (move == KB_LEFT) {
        move = KB_RIGHT;
        return;
    }
    move = KB_LEFT;
    return;
}
int Move::up_down(Location player, Location enemy) {
    if (player.row < enemy.row)
        return KB_UP;
    else
        return KB_DOWN;
}
int Move::right_left(Location player, Location enemy) {
    if (player.col < enemy.col)
        return KB_LEFT;
    else
        return KB_RIGHT;;
}

*/
/*sf::Vector2f player_loc(*(sf::Vector2f*)PlayerLoction);
	if (m_Elemnt_Of_Game.getPosition().x > player_loc.x&&
		m_Elemnt_Of_Game.getPosition().y - player_loc.y<1.0f)
	{
		sf::Vector2f next(-1, 0);
		this->move_Object(next, deltaTime, m_All_Objects);
		
	}
	if (m_Elemnt_Of_Game.getPosition().x < player_loc.x &&
		m_Elemnt_Of_Game.getPosition().y - player_loc.y < 1.0f)
	{
		sf::Vector2f next(1, 0);
		this->move_Object(next, deltaTime, m_All_Objects);
		
	}
	if (What_In_Loc(m_Elemnt_Of_Game, m_All_Objects) == ladder)
	{
		if (m_Elemnt_Of_Game.getPosition().y - player_loc.y < 1.0f)
		{
			sf::Vector2f next(0, 1);
			this->move_Object(next, deltaTime, m_All_Objects);
		}
		if (m_Elemnt_Of_Game.getPosition().y - player_loc.y > 1.0f)
		{
			sf::Vector2f next(0, -1);
			this->move_Object(next, deltaTime, m_All_Objects);
		}
	}*/