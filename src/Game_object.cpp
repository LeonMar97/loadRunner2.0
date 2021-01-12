#include "Game_Object.h"
 void Game_Object::draw_On_Board(sf::RenderWindow& game_screen) {
	 if(this->print_me)
	 game_screen.draw(this ->m_Elemnt_Of_Game);
}
 sf::Vector2f Game_Object:: get_loction()const
 {
	 return m_Elemnt_Of_Game.getPosition();
 }
 void Game_Object::set_loction(sf::Vector2f &new_loc)
 {
	 m_Elemnt_Of_Game.setPosition(new_loc);
 }
 //==================================================
 sf::RectangleShape Game_Object::get_rectangle()const
 {
	 return m_Elemnt_Of_Game;
 }