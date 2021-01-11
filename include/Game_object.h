#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#include "enums_End_Consts.h"
#pragma once
class Movable;
class Money;
class Gift;
class Enemy;
class Player;
class Game_Object {

public:
    //-----------------------------functions------------------------------//
    Game_Object(sf::RectangleShape cur_rec,  std::vector<sf::Texture*>tex, char icon = ' ') :
        m_Elemnt_Of_Game(cur_rec),
        m_Tex(tex), m_Type(icon) {
        m_Elemnt_Of_Game.setTexture(m_Tex[0]);
    }
                                                                            
    virtual void handleCollision(Game_Object& gameObject) = 0;
    virtual void handleCollision(Player& gameObject) = 0;
    virtual void handleCollision(Enemy& gameObject) = 0;
    virtual void handleCollision(Gift& gameObject) = 0;
    virtual void handleCollision(Money& gameObject) = 0;
   virtual void draw_On_Board(sf::RenderWindow &game_screen) ;
   virtual void effect(void*, std::vector<Game_Object*>m_All_Objects[NUM_OF_OBJECTS]) {};

   char get_Type() const { return m_Type; };
   sf::Vector2f get_loction()const;
   void set_loction(sf::Vector2f& new_loc);
   sf::RectangleShape get_rectangle()const;
  
    //virtual void effect() = 0;
protected:
    
     sf::RectangleShape m_Elemnt_Of_Game;
     char m_Type;//just to know which object is it
     std::vector<sf::Texture*>m_Tex;//for the textures.
};
