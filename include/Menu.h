#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>

#define MAX_NUMBER_OF_ITEM 2

class Menu
{
public:
	Menu();
    void draw(sf::RenderWindow& Window);
	void Move_Up();
		void Move_Down();
		int Get_Pressed() { return m_selectedItem; }
		
	//~Menu();
private:
	   int m_selectedItem;
	   sf::Font m_font;
	   sf::Text m_text[MAX_NUMBER_OF_ITEM];
	   sf::Sprite m_Menu_Background;
	  
};