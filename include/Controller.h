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
		void start_Game();
		~Controller() { delete_vector(); }
//--------------private--------functions-----------------------//		
	private:
		
		
		void set_G_O_Vector();//set vector with all obhect in game
		void  free_Fall();//check if object is in thr air ,and drop it one step down if does in controller so it look real falling
		void draw_On_map();//
		
		void updateGameObjects();//move all moving object in the game
		void restart_lvl();
		void check_Erace();//delete money/gifts we already collected
		void check_Hits();
		void game_Time();//set game clock on screen
		void check_Gifts();//if we colllected gift so check what gift we collect
		void delete_vector();
		void check_Rest_Time();//check if we running out of time for corrent lvl 
		void draw_Time();
		void check_Score();//check if we collected all the money in curr lvl
		void check_Lives();//check how much lives left for player 
		void set_Score_Board();
		void draw_all();
		void Quit_Game(int pic_num);//quit game if need to
		Game_Object* random_Enemy(sf::RectangleShape cur_Rec, sf::Vector2f rec_Loc);//make sure we have random enemys every lvl
//------------------members-----------------------------------//		
	private :
		sf::RenderWindow m_Game_Window;
		Board m_Board;
		std::vector<Game_Object*>m_All_Objects[NUM_OF_OBJECTS];//for printing after drawing for displaying
		sf::Clock m_Clock;//moving clock
		sf::Clock m_Game_Clock;//game clock
		
		sf::Sprite m_Bg; // the background
	
		sf::Text time_to_screen;
		int m_Lvl=1;
		int m_Player_enter_score = 0;
		Menu m_Game_menu;
		
		Score_Board m_ScoreBoard;
	};
	