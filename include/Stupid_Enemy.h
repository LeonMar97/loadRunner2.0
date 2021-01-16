#include <cstdlib>
#include <iostream>
#include "Disappearing_Object.h"
#include <ctime>
#include "Enemy.h"

#pragma once
class Stupid_Enemy :public Enemy {
public:
	//using Disappearing_Object::Disappearing_Object;
	Stupid_Enemy(sf::RectangleShape cur_rec, sf::Vector2f loction) :
		Enemy(cur_rec, (Textures::instance().get_Textures(stupidEnemys_T)), (loction), (enemy)) {
	}
	
private:
	void effect(void* PlayerLoction, std::vector<Game_Object*>m_All_Objects[NUM_OF_OBJECTS])override;
	sf::Clock m_clock;
	int m_Wall=1;
	//void set_Sounds();

};


