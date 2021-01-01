#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#include "Moving_Object.h"
#pragma once
class Player :protected Moving_Object {
public:
	Player(sf::Vector2f player_first_loc);
	//virtual void move();
	//bool getmovement();
	//bool handleSpecialKey(int c);
	//bool location_valid(sf::Sprite next);
	//int get_lives();
	//int get_score();
private:
	sf::Sprite m_Player;
	int m_Score = 0, m_Lives = 3;
	sf::Texture* m_Pic;
};
