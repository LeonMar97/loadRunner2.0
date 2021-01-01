
#pragma once
class Disapearing_Object {

public://functions
    Game_Object() = 0;
    virtual void draw_On_Board() = 0;
    virtual void effect() = 0;
private:

private:    //members
    sf::RenderWindow m_Game_screen;
    sf::Sprite elemnt_Of_Game;

}

