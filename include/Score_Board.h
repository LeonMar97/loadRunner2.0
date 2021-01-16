#include <cstdlib>
#include <iostream>
#include "Sounds_E.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Game_object.h"
#include "Textures.h"

class Score_Board {

	//~~~~~~~~~~~~~~~~~~~~~~~functions~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
public:
	Score_Board(sf::Vector2f print_Loc = sf::Vector2f(0.f, 0.f));
	void set_Scores(int lvl, Game_Object& main_Player);
	void draw_Scoreboard(sf::RenderWindow& game_Window, int lvl, Game_Object& main_Player);
	void set_Location(sf::Vector2f print_Loc)  ;
	//~~~~~~~~~~~~~~~~~~~~~~~members~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
private:

	sf::Text m_Scoreboard_Text[3];
	sf::Sprite m_Bg;
	sf::Vector2f m_Printloc;
};



