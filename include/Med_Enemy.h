#include <cstdlib>
#include <iostream>
#include "Disappearing_Object.h"
#include <ctime>
#pragma once
class Med_Enemy :public Enemy {
public:
	//using Disappearing_Object::Disappearing_Object;
	Med_Enemy(sf::RectangleShape cur_rec, sf::Vector2f loction) :
		Enemy(cur_rec, (Textures::instance().get_Textures(medEnemys_T)), (loction), (enemy)) {
		m_Elemnt_Of_Game.setOrigin(sf::Vector2f(m_Elemnt_Of_Game.getGlobalBounds().width / 2,
			m_Elemnt_Of_Game.getGlobalBounds().height / 2));
	}

	
private:
	void effect(void* PlayerLoction, std::vector<Game_Object*>m_All_Objects[NUM_OF_OBJECTS])override;
	sf::Clock m_clock;
	int m_Wall = 1;



};


