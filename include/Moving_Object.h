#include "Game_Object.h"
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#pragma once
class Moving_Object : public Game_Object {
//--------------public--------functions-----------------------//
public:	
	using Game_Object::Game_Object;
	virtual void move()=0;	
};
