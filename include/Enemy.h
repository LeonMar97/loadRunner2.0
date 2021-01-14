#include <cstdlib>
#include <iostream>
#include "Moving_Object.h"
#pragma once
class Enemy :public Moving_Object {
	//--------------public--------functions-----------------------//
public:
	using Moving_Object::Moving_Object;
	void handleCollision(Game_Object& gameObject)override;
	void handleCollision(Enemy& gameObject)override ;
	void handleCollision(Money& gameObject)override ;
	void handleCollision(Player& gameObject)override ;
	void handleCollision(Gift& gameObject)override ;
	sf::Vector2f dirFromKey();
	void effect(void* deltaTime, std::vector<Game_Object*>m_All_Objects[NUM_OF_OBJECTS]);
//--------------private--------members-----------------------//
private:
	sf::Clock m_enemy_Clock;
};