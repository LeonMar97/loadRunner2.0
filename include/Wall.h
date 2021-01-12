#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#include "Disappearing_Object.h"
#pragma once
class Wall :public Disappearing_Object {
public:
	using Disappearing_Object::Disappearing_Object;
	void handleCollision(Player& enemy) ;


private:
	
};

