#include <cstdlib>
#include <iostream>
#include "Disappearing_Object.h"
#include <ctime>

#pragma once
class Stupid_Enemy :public Enemy {
public:
	//using Disappearing_Object::Disappearing_Object;
	Stupid_Enemy(sf::RectangleShape cur_rec, sf::Vector2f loction) :
		Enemy(cur_rec, (Textures::instance().get_Textures(stupidEnemys_T)), (loction), (enemy)) {
	}

private:


	//void set_Sounds();

};


