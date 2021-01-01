
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#pragma once
class Moving_Object: public Game_object{
public:
	Moving_Object() {};
	virtual void move() {};

private:
	//sf::Sprite elemnt_Of_Game;
