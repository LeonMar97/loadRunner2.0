#include <vector>
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Game_object.h"
#pragma once
	class Controller {

//--------------public--------functions-----------------------//
	public:
		Controller();
		
//--------------private--------functions-----------------------//		
	private:
	void start_game();
		
		
//------------------members-----------------------------------//		
	private :
		sf::RenderWindow m_Game_Window;
		Board m_Board;
		std::vector<Game_Object*>m_All_Objects;//for printing after drawing for displaying
		sf::Clock m_Clock;

	};
	