#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#include "Disappearing_Object.h"
#pragma once
class Gift :public Disappearing_Object{
public:
	using Disappearing_Object::Disappearing_Object;
	void handleCollision(Game_Object& gameObject)override {};
	void handleCollision(Enemy& gameObject)override {};
	void handleCollision(Money& gameObject)override {};
	void handleCollision(Player& gameObject)override {};
	void handleCollision(Gift& gameObject)override {};
	
private:
	
	
};


