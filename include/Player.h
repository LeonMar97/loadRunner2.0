#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#pragma once
class Player : public Moving_Object {
public:
	Player();
	virtual void move();
	int get_lives();
	int get_score();
private:
	sf::Sprite m_player;
	int m_score = 0,m_lives=3;

}