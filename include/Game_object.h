#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#include "enums_End_Consts.h"
#pragma once
class Game_Object {

public:
    //-----------------------------functions------------------------------//
    Game_Object(sf::RectangleShape cur_rec ,char icon=' ') : m_Elemnt_Of_Game(cur_rec),
                                                                            m_Type(icon){};
   virtual void draw_On_Board(sf::RenderWindow &game_screen) ;
   char get_Type() const { return m_Type; };
   // virtual void effect() = 0;
private:
     sf::RectangleShape m_Elemnt_Of_Game;
     char m_Type;//just to know which object is it

};
