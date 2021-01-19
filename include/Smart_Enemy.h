#include <cstdlib>
#include <iostream>
#include "Disappearing_Object.h"
#include <ctime>
#pragma once
class Smart_Enemy :public Enemy {
public:
	//using Disappearing_Object::Disappearing_Object;
	Smart_Enemy(sf::RectangleShape cur_rec, sf::Vector2f loction) :
		Enemy(cur_rec, (Textures::instance().get_Textures(smartEnemys_T)), (loction), (enemy)) {
		m_Elemnt_Of_Game.setOrigin(sf::Vector2f(m_Elemnt_Of_Game.getGlobalBounds().width / 2,
			m_Elemnt_Of_Game.getGlobalBounds().height / 2));
	}

private:
	void effect(void* PlayerLoction, std::vector<Game_Object*>m_All_Objects[NUM_OF_OBJECTS])override;
	sf::Vector2f up_down(sf::Vector2f player_loc, sf::Vector2f my_loc);
	sf::Vector2f right_left(sf::Vector2f player_loc, sf::Vector2f my_loc);
	sf::Clock m_clock;
	bool m_is_Wall = false;
	//void set_Sounds();

};
