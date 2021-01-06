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
		//void swap_Location();
		void  free_Fall();
		//char What_In_Loc(Game_Object &);
		void draw_On_map();
		
//------------------members-----------------------------------//		
	private :
		sf::RenderWindow m_Game_Window;
		Board m_Board;
		
		std::vector<Game_Object*>m_All_Objects[NUM_OF_OBJECTS];//for printing after drawing for displaying
		sf::Clock m_Clock;
		int m_Enemys = 0;
	};
	