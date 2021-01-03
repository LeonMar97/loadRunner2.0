#include "Game_Object.h"
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#pragma once
class Moving_Object : public Game_Object {
//--------------public--------functions-----------------------//
public:	
	using Game_Object::Game_Object;
	//using Game_Object::effect;
	//virtual void move(sf::Keyboard::Key key) {};
	void effect(void* key)override;
	
	
	
	
	
};
