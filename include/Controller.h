#include <vector>
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Game_Object.h"
#include "Moving_Object.h"
#include "Money.h"
#include "Gift.h"
#include "Enemy.h"
#include "Player.h"
#include "Wall.h"
#pragma once

class Controller {

//--------------public--------functions-----------------------//
	public:
		Controller();
		void start_Game();
//--------------private--------functions-----------------------//		
	private:
		void set_G_O_Vector();
		void swap_Location();
		void  free_fall(int);
		char What_In_Loc(Game_Object &);
			
		
//------------------members-----------------------------------//		
	private :
		sf::RenderWindow m_Game_Window;
		Board m_Board;
		std::vector<Game_Object*>m_All_Objects;//for printing after drawing for displaying
		sf::Clock m_Clock;
		int m_Enemys = 0;
	};
	