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
	}

	void handleCollision(Game_Object& gameObject)override {};
	void handleCollision(Enemy& gameObject)override {};
	void handleCollision(Money& gameObject)override {};
	void handleCollision(Gift& gameObject)override {};
	
private:
	



};


