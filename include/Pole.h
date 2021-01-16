#pragma once
#include <cstdlib>
#include <iostream>
#include "Disappearing_Object.h"
class Pole :public Disappearing_Object {
public:
	using Disappearing_Object::Disappearing_Object;
	Pole(sf::RectangleShape cur_rec, sf::Vector2f loction) :
		Disappearing_Object(cur_rec, (Textures::instance().get_Textures(poles_T)), (loction), (pole)) {

		m_Elemnt_Of_Game.setScale(1, 0.1);
		m_Elemnt_Of_Game.setFillColor(sf::Color::Red);
		m_Elemnt_Of_Game.setOutlineColor(sf::Color::Red);
	}


private:

};
