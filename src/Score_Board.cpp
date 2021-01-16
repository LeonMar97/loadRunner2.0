#include "Score_Board.h"
#include "Player.h"

Score_Board::Score_Board(sf::Vector2f print_Loc)

	:m_Bg(*Textures::instance().get_Textures(scoreboard_T)[0]),m_Printloc(print_Loc)
{

	m_Scoreboard_Text[sc].setString(std::to_string(0));
	m_Scoreboard_Text[lvl].setString(std::to_string(1));
	m_Scoreboard_Text[lf].setString(std::to_string(5));

	m_Bg.setPosition(m_Printloc);

	float s = m_Bg.getGlobalBounds().height / 5;
	for (int i = 0; i <= lf; i++) {

		m_Scoreboard_Text[i].setFont(Textures::instance().get_Font());
		m_Scoreboard_Text[i].setFillColor(sf::Color::Red);
		m_Scoreboard_Text[i].setCharacterSize(24);
		m_Scoreboard_Text[i].setStyle(sf::Text::Bold | sf::Text::Underlined);
		m_Scoreboard_Text[i].setPosition(m_Bg.getPosition().x + m_Bg.getGlobalBounds().width / 2,
			m_Bg.getPosition().y + ((s) * (i + 1) + (i * s) / 2));

	}

}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
//setting current player score

void Score_Board::set_Scores(int lvl, Game_Object& main_Player) {
	m_Scoreboard_Text[sc].setString(std::to_string((dynamic_cast<Player*>(&main_Player))->getscore()));
	m_Scoreboard_Text[lvl].setString(std::to_string(lvl));
	m_Scoreboard_Text[lf].setString(std::to_string((dynamic_cast<Player*>(&main_Player))->getlives()));

}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

void Score_Board::draw_Scoreboard(sf::RenderWindow& game_Window, int lvl, Game_Object& main_Player) {
	set_Scores(lvl, main_Player);
	
	game_Window.draw(m_Bg);
	for (int i = 0; i <= lf; i++) {
		game_Window.draw(m_Scoreboard_Text[i]);
	}

	
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
void Score_Board:: set_Location(sf::Vector2f print_Loc) {
	m_Printloc = print_Loc;
	m_Printloc.x -=m_Bg.getGlobalBounds().width / 2;
	m_Bg.setPosition(m_Printloc);

	float s = m_Bg.getGlobalBounds().height / 5;
	for (int i = 0; i <= lf; i++) {

		m_Scoreboard_Text[i].setPosition(m_Bg.getPosition().x + m_Bg.getGlobalBounds().width / 2,
			m_Bg.getPosition().y + ((s) * (i + 1) + (i * s) / 2));

	}
	
	

}



//(dynamic_cast<Player*>(&main_Player))->getlives())
//game_Window.draw(m_Bg);
