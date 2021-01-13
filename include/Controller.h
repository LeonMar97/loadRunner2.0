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
#include "Ladder.h"
#pragma once

class Controller {

//--------------public--------functions-----------------------//
	public:
		Controller();
		void start_Game();
//--------------private--------functions-----------------------//		
	private:
		void set_G_O_Vector();
		void  free_Fall();
		void draw_On_map();
		void load_pic(std::vector<sf::Texture*>all_Objects[NUM_OF_OBJECTS]);
		void updateGameObjects();
		void draw_Score_Board();
		void check_Erace();
		void check_Hits();
		void set_Background_And_Score();
		void check_Gifts();
		void delete_vector();
		void check_Rest_Time();
		void draw_Time();
		void check_Score();
//------------------members-----------------------------------//		
	private :
		sf::RenderWindow m_Game_Window;
		Board m_Board;
		std::vector<Game_Object*>m_All_Objects[NUM_OF_OBJECTS];//for printing after drawing for displaying
		sf::Clock m_Clock;//moving clock
		sf::Clock m_Game_Clock;//game clock
		int m_Enemys = 0;
		sf::Sprite m_bg; // the background
		sf::Text m_Scoreboard_Text[3];
		sf::Text time_to_screen;
		sf::RectangleShape m_Score_Board;
		int m_Lvl=1;
		int m_money_Took = 0;
	};
	