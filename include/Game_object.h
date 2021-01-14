#include <cstdlib>
#include <iostream>
#include "Sounds_E.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#pragma once
class Moving_Object;
class Money;
class Gift;
class Enemy;
class Player;
class Wall;
class Game_Object {

public:
    //-----------------------------functions------------------------------//
     Game_Object(sf::RectangleShape cur_rec,  std::vector<sf::Texture*>tex,sf::Vector2f loction, char icon = ' ') :
        m_Elemnt_Of_Game(cur_rec),
        m_Tex(tex),m_first_Loc(loction), m_Type(icon) {
        m_Elemnt_Of_Game.setTexture(m_Tex[0]);
    }
    ~Game_Object()=default;
    virtual void handleCollision(Game_Object& gameObject) = 0;
    virtual void handleCollision(Player& gameObject) = 0;
    virtual void handleCollision(Enemy& gameObject) = 0;
    virtual void handleCollision(Gift& gameObject) = 0;
    virtual void handleCollision(Money& gameObject) = 0;
    virtual void handleCollision(Wall& enemy) = 0;
   virtual void draw_On_Board(sf::RenderWindow &game_screen) ;
   virtual void effect(void*, std::vector<Game_Object*>m_All_Objects[NUM_OF_OBJECTS]) {};

   char get_Type() const { return m_Type; }
   sf::Vector2f get_loction()const;
   void set_loction(sf::Vector2f& new_loc);
   sf::RectangleShape get_rectangle()const;
   sf::Vector2f get_First_loc() { return m_first_Loc; }
   bool get_Print_Me()const { return print_me; }
   void set_Print_Me(bool item) { print_me=item; }
    //virtual void effect() = 0;
protected:
    
     sf::RectangleShape m_Elemnt_Of_Game;
     char m_Type;//just to know which object is it
     std::vector<sf::Texture*>m_Tex;//for the textures.
     sf::Vector2f m_first_Loc;
     bool print_me = true;
};
