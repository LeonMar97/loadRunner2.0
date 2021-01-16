#include <cstdlib>
#include <iostream>
#include "Moving_Object.h"
#include "Textures.h"
#pragma once
class Enemy :public Moving_Object {
	//--------------public--------functions-----------------------//
public:
	using Moving_Object::Moving_Object;
	Enemy(sf::RectangleShape cur_rec, sf::Vector2f loction) :
		Moving_Object(cur_rec, (Textures::instance().get_Textures(smartEnemys_T)), (loction), (enemy)) {
		m_Elemnt_Of_Game.setOrigin(sf::Vector2f(m_Elemnt_Of_Game.getGlobalBounds().width / 2,	
												m_Elemnt_Of_Game.getGlobalBounds().height / 2));
	}
	void handleCollision(Game_Object& gameObject)override ;
	void handleCollision(Enemy& gameObject)override ;
	void handleCollision(Money& gameObject)override ;
	void handleCollision(Player& gameObject)override ;
	void handleCollision(Gift& gameObject)override ;
	void handleCollision(Wall& gameObject)override;
//--------------private--------members-----------------------//
protected:
	sf::Time m_last_Checked_Time;

};