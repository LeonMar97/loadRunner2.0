#include <vector>
#include <string>
#include <iostream>
#include "Board.h"
#include "Game_Object.h"
#include "Moving_Object.h"
#include "Money.h"
#include "Gift.h"
#include "Enemy.h"
#include "Player.h"
#include "Wall.h"
#include "Ladder.h"
#include "Menu.h"
#include "Pole.h"
#include "Textures.h"
#include "Med_Enemy.h"
#include "Smart_Enemy.h"
#include "Stupid_Enemy.h"
#include "Score_Board.h"
#pragma once

class Controller {

//--------------public--------functions-----------------------//
	public:
		Controller();
		~Controller() { delete_vector(); }
		void start_Game();
//--------------private--------functions-----------------------//		
	private:
		void set_G_O_Vector();
		void  free_Fall();
		void draw_On_map();
		//void load_pic();
		void updateGameObjects();
		//void draw_Score_Board();
		void check_Erace();
		void check_Hits();
		void game_Time();
		void check_Gifts();
		void delete_vector();
		void check_Rest_Time();
		void draw_Time();
		void check_Score();
		void check_Lives();
		void set_Score_Board();
		void print_Background();
		void Quit_Game(int pic_num);
		Game_Object* random_Enemy(sf::RectangleShape cur_Rec, sf::Vector2f rec_Loc);
//------------------members-----------------------------------//		
	private :
		sf::RenderWindow m_Game_Window;
		Board m_Board;
		std::vector<Game_Object*>m_All_Objects[NUM_OF_OBJECTS];//for printing after drawing for displaying
		sf::Clock m_Clock;//moving clock
		sf::Clock m_Game_Clock;//game clock
		
		sf::Sprite m_bg; // the background
	
		sf::Text time_to_screen;
		int m_Lvl=1;
		int m_Player_enter_score = 0;
		Menu m_Game_menu;
		std::vector<sf::Texture*>m_All_textures[NUM_OF_OBJECTS];
		Score_Board m_ScoreBoard;
	};
	