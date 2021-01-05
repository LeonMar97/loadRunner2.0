#include "Game_Object.h"
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#pragma once
class Moving_Object : public Game_Object {
//--------------public--------functions-----------------------//
public:	
	using Game_Object::Game_Object;
	//using Game_Object::effect;
	//virtual void move(sf::Keyboard::Key key) {};
	bool check_movment(sf::RectangleShape& cur_loc, std::vector<Game_Object*>& m_All_Objects, 
																						sf::RectangleShape& last_loc);
	void effect(void* key, std::vector<Game_Object*>&m_All_Objects)override;
	bool check_ladder(sf::RectangleShape& cur_loc, std::vector<Game_Object*>& m_All_Objects, sf::Vector2f last_loc);
	char What_In_Loc(sf::RectangleShape& afterclick_Loc, std::vector<Game_Object*>& m_All_Objects);
	
private:
	bool direction = true;
};
