#pragma once
#include <cstdlib>
#include <iostream>
#include "Disappearing_Object.h"
class Ladder :public Disappearing_Object {
public:
	using Disappearing_Object::Disappearing_Object;
	Ladder(sf::RectangleShape cur_rec, sf::Vector2f loction) :
		Disappearing_Object(cur_rec, (Textures::instance().get_Textures(ladders_T)), (loction), (ladder)) {
		m_Elemnt_Of_Game.setScale(1, 1.1);
	}


private:

};
