#include "Wall.h"
#include <time.h>
//dont print wall if we digged
void Wall::handleCollision(Player& player)
{
	if (print_me)
	{
		print_me = false;
		m_Wall_clock.restart();
	}
}
//============================================
//if time for hole is 0 and object inside so move him up
void Wall::Check_Wall(Player& player, std::vector<Game_Object*>& enemeys)
{
	if (m_Wall_clock.getElapsedTime().asSeconds() > 5)
	{
		print_me = true;
		if (this->get_rectangle().getGlobalBounds().intersects(player.get_rectangle().getGlobalBounds()))
			player.handleCollision(*this);
		for (int i = 0; i < enemeys.size(); i++)
		{
			if (this->get_rectangle().getGlobalBounds().intersects(enemeys[i]->get_rectangle().getGlobalBounds()))
				enemeys[i]->handleCollision(*this);
		}
	}
}
//============================================
