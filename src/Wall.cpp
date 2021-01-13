#include "Wall.h"
#include <time.h>

void Wall::handleCollision(Player& player)
{
	print_me = false;
	m_Wall_clock.restart();
}
//============================================
void Wall::Check_Wall(Player& player)
{
	if (m_Wall_clock.getElapsedTime().asSeconds() > 5)
	{
		print_me = true;
		if (this->get_rectangle().getGlobalBounds().intersects(player.get_rectangle().getGlobalBounds()))
			player.handleCollision(*this);
	}
}