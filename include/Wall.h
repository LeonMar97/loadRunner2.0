#include <cstdlib>
#include <iostream>
#include "Disappearing_Object.h"

#pragma once
class Wall :public Disappearing_Object {
public:
	using Disappearing_Object::Disappearing_Object;
	Wall(sf::RectangleShape cur_rec, sf::Vector2f loction) :
		Disappearing_Object(cur_rec, (Textures::instance().get_Textures(walls_T)), (loction), (wall)) {
		m_Elemnt_Of_Game.setOutlineThickness(1);
		m_Elemnt_Of_Game.setOutlineColor(sf::Color::Black);
		m_Elemnt_Of_Game.setScale(1, 0.9);
	}
	void handleCollision(Player& enemy) ;
	void  Check_Wall(Player& player, std::vector<Game_Object*>& enemeys);

private:
	sf::Clock m_Wall_clock;
};

