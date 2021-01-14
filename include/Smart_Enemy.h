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
	}

private:


	//void set_Sounds();

};
