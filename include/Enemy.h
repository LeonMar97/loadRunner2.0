#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#include "Moving_Object.h"
#pragma once
class Enemy :public Moving_Object {
	//--------------public--------functions-----------------------//
public:
	using Moving_Object::Moving_Object;
	//Player(sf::Vector2f player_first_loc);
	virtual void move() {};//using the move of the moving object
	//bool getmovement();
	//bool handleSpecialKey(int c);
	//bool location_valid(sf::Sprite next);
	//int get_lives();
	//int get_score();
//--------------private--------members-----------------------//
};