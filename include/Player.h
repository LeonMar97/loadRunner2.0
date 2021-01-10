#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#include "Moving_Object.h"
#pragma once
class Player :public Moving_Object {
//--------------public--------functions-----------------------//
public:
	using Moving_Object::Moving_Object;

	

	//Player(sf::Vector2f player_first_loc);
	//virtual void move() {};//using the move of the moving object
	void setscore(int);
	int getscore()const;
	int getlives()const;
	void setlives(int);
	void effect(void* DeltaTime, std::vector<Game_Object*>m_All_Objects[NUM_OF_OBJECTS])override;
	sf::Vector2f dirFromKey();
	//void effect(void *)override;
	//bool getmovement();
	//bool handleSpecialKey(int c);
	//bool location_valid(sf::Sprite next);
	//int get_lives();
	//int get_score();
//--------------private--------members-----------------------//
private:
	int m_Score = 0, m_Lives = 3;

};
