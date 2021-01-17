#include "Med_Enemy.h"





void Med_Enemy::effect(void* PlayerLoction, std::vector<Game_Object*>m_All_Objects[NUM_OF_OBJECTS])
{
	
	auto deltaTime = m_clock.restart();
	//sf::Vector2f player_loc(*(sf::Vector2f*)PlayerLoction);
	sf::RectangleShape temp(m_Elemnt_Of_Game);
	sf::Vector2f next(m_Wall, 0);

	float size = (temp.getTexture()->getSize().x) / 3;
	temp.move(next * size * deltaTime.asSeconds());

	if (What_In_Loc(temp, m_All_Objects) == wall)
	{
		m_Wall *= -1;

	}

	sf::Vector2f next_step(m_Wall, 0);
	this->move_Object(next_step, deltaTime, m_All_Objects);
}



