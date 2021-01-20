#include "Stupid_Enemy.h"

//stupid alguritem to random ser dir each 4 sec
void Stupid_Enemy::effect(void* PlayerLoction, std::vector<Game_Object*>m_All_Objects[NUM_OF_OBJECTS])
{
	
	auto deltaTime = m_clock.restart();
	if (m_clock_enemy.getElapsedTime().asSeconds() > 4)
	{
		m_clock_enemy.restart();
		

	
		switch (rand() % 4 + 1)

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


