#include "Stupid_Enemy.h"


void Stupid_Enemy::effect(void* PlayerLoction, std::vector<Game_Object*>m_All_Objects[NUM_OF_OBJECTS])
{
	auto deltaTime = m_clock.restart();
	//sf::Vector2f player_loc(*(sf::Vector2f*)PlayerLoction);
	//sf::RectangleShape temp(m_Elemnt_Of_Game);
	//sf::Vector2f next(m_Wall, 0);

	//float size = (m_Elemnt_Of_Game.getTexture()->getSize().x) / 3;
	//temp.move(next * size * deltaTime.asSeconds());
	int x, y;
	switch(rand()%4+1)
	{
	case 1:
		x = 1, y = 0;
		break;
	case 2:
		x = -1, y = 0;
		break;
	case 3:
		x = 0, y = 1;
		break;
	case 4:
		x = 0, y = -1;
		break;
		
	}

	sf::Vector2f next_step(x, y);
	this->move_Object(next_step, deltaTime, m_All_Objects);
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