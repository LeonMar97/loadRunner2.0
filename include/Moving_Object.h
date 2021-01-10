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
	bool check_movment(sf::RectangleShape& cur_loc, std::vector<Game_Object*>m_All_Objects[],
																						Game_Object &last_Loc);
	void effect(void* key, std::vector<Game_Object*>m_All_Objects[NUM_OF_OBJECTS])override;
	bool check_ladder(sf::RectangleShape& cur_Loc, std::vector<Game_Object*>m_All_Objects[],
							  											Game_Object& last_Loc);
	char What_In_Loc(sf::RectangleShape& temp, std::vector<Game_Object*>m_All_Objects[]);
	void on_Floor( std::vector<Game_Object*>m_All_Objects[]);
	bool check_pole(std::vector<Game_Object*>m_All_Objects[],
		Game_Object& last_Loc, sf::RectangleShape& cur_Loc);
	bool check_space(std::vector<Game_Object*>m_All_Objects[],
		Game_Object& last_Loc, sf::RectangleShape& cur_Loc);
	void move_to_center_ladder(std::vector<Game_Object*>m_All_Objects[]);
	void change__Curr_Texture(std::vector<Game_Object*>m_All_Objects[]);
	void move_to_center_pole(std::vector<Game_Object*>m_All_Objects[]);
private:
	bool direction = true;
};
