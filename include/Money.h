#pragma once
#include <cstdlib>
#include <iostream>
#include "Disappearing_Object.h"
#include"Textures.h"
class Money :public Disappearing_Object {
public:

	Money(sf::RectangleShape cur_rec, sf::Vector2f loction) :
		Disappearing_Object(cur_rec, (Textures::instance().get_Textures(moneys_T)), (loction), (money)) {
		m_Elemnt_Of_Game.setScale(0.5, 0.5);
	
	}
	
	void handleCollision(Game_Object& gameObject)override;
	void handleCollision(Enemy& gameObject)override;
	void handleCollision(Money& gameObject)override;
	void handleCollision(Player& gameObject)override;

	void handleCollision(Gift& gameObject)override {};
private:

	

};


