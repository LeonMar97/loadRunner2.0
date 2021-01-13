#pragma once
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#include "Disappearing_Object.h"

class Money :public Disappearing_Object {
public:
	Money(sf::RectangleShape cur_rec, std::vector<sf::Texture*>tex, sf::Vector2f loction, char icon = ' ') :
		Disappearing_Object(cur_rec, (tex), (loction), (icon)) {
		
		m_Num_of_Money++;
		std::cout << m_Num_of_Money << "\n";
	}
	
	void handleCollision(Game_Object& gameObject)override;
	void handleCollision(Enemy& gameObject)override;
	void handleCollision(Money& gameObject)override;
	void handleCollision(Player& gameObject)override;
	

private:
	static int m_Num_of_Money ;
};


