#include "Stupid_Enemy.h"


void Stupid_Enemy::effect(void* PlayerLoction, std::vector<Game_Object*>m_All_Objects[NUM_OF_OBJECTS])
{
	int x,y;
	auto deltaTime = m_clock.restart();
	if (m_clock_enemy.getElapsedTime().asSeconds() > 4)
	{
		m_clock_enemy.restart();
		

	
		switch (rand() % 4 + 1)
		//switch (1)
		{
		case 1:
			m_direction.x = 1, m_direction.y = 0;
			break;
		case 2:
			m_direction.x =-1, m_direction.y = 0;
			break;
		case 3:
			m_direction.x = 0, m_direction.y = 1;
			break;
		case 4:
			m_direction.x = 0, m_direction.y = -1;

			break;

		}
	}

	this->move_Object(m_direction, deltaTime, m_All_Objects);
}



/*auto deltaTime = clock.restart();
	sf::Vector2f player_loc(*(sf::Vector2f*)PlayerLoction);
	if (m_Elemnt_Of_Game.getPosition().x > player_loc.x)
	{
		sf::Vector2f next(-1, 0);
		this->move_Object(next, deltaTime, m_All_Objects);
	}
	else {
		sf::Vector2f next(1, 0);
		this->move_Object(next, deltaTime, m_All_Objects);
	}
	*/

/**/