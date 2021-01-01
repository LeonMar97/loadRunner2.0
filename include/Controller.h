#include <vector>
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Game_object.h"
#include "Player.h"
#pragma once

class Controller {

//--------------public--------functions-----------------------//
	public:
		Controller() :m_Game_Window(sf::VideoMode(1920, 1080), "Game") {};
		void start_Game();
		void set_G_O_Vector();
//--------------private--------functions-----------------------//		
	private:
	
		
		
//------------------members-----------------------------------//		
	private :
		sf::RenderWindow m_Game_Window;
		Board m_Board;
		std::vector<Game_Object*>m_All_Objects;//for printing after drawing for displaying
		sf::Clock m_Clock;

	};
	