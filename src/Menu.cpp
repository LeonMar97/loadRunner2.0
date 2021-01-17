#pragma once
#include "Menu.h"
#include "Textures.h"

Menu::Menu()
	:m_Menu_Background(*Textures::instance().get_Textures(menu_T)[0])
{
	
	
	m_font =(Textures::instance().get_Font());
	m_text[0].setFont(m_font);
	m_text[0].setColor(sf::Color::Black);
	m_text[0].setOutlineThickness(4);
	m_text[0].setOutlineColor(sf::Color::Green);
	m_text[0].setString("Start");
	
	m_text[0].setPosition(sf::Vector2f(1980 / 2-((m_text[0].getCharacterSize()*5)/2), 1080/ (MAX_NUMBER_OF_ITEM + 1) * 1));

    m_text[1].setFont(m_font);
	m_text[1].setColor(sf::Color::Black);
	m_text[1].setOutlineThickness(4);
	m_text[1].setOutlineColor(sf::Color::White);
	m_text[1].setString("Leave");
	m_text[1].setPosition(sf::Vector2f(m_text->getPosition().x, 1080 / (MAX_NUMBER_OF_ITEM + 1) * 2));
	m_selectedItem = 0;
	

}

void Menu::draw(sf::RenderWindow& window)
{
	bool in_menu = true;
	sf::Event event;
	while (in_menu)
	{
		sf::Vector2i cursorPos;
		window.clear();
		window.draw(m_Menu_Background);
		for (int i = 0; i < MAX_NUMBER_OF_ITEM; i++)
		{
			window.draw(m_text[i]);
		}
		window.display();
		while (window.pollEvent(event))
		{
			window.clear();
			switch (event.type) {
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					Move_Up();
					break;
				case sf::Keyboard::Down:
					Move_Down();
					break;
				case sf::Keyboard::Enter:
					Get_Pressed(window);
					return;
				};
				break;
			case sf::Event::Closed:
				window.close();
				in_menu = false;
				break;
			case  sf::Event::MouseMoved:

				cursorPos = sf::Mouse::getPosition(window);

				mouseHover(cursorPos);//sending event to know if text was click or not
				break;
			case sf::Event::MouseButtonReleased:
				if (mouse_Click(cursorPos));
				Get_Pressed(window);
				return;
			};
			break;
		}
	}

}


void  Menu::Get_Pressed(sf::RenderWindow &window) {
	if(m_selectedItem==1 )
		window.close();	
}





//returns if clicked on the text
bool Menu:: mouse_Click(sf::Vector2i cursorPos) {
	return (m_text[0].getGlobalBounds().contains(sf::Vector2f(cursorPos)) || m_text[1].getGlobalBounds().contains(sf::Vector2f(cursorPos)));
}

//checks if mouse above requested element
void Menu:: mouseHover( sf::Vector2i curserPos) {

	
		if (m_text[0].getGlobalBounds().contains(sf::Vector2f(curserPos))) {
			if (m_selectedItem == 1) { //if the quit button  pressed
				m_text[0].setOutlineColor(sf::Color::Green);
				m_text[1].setOutlineColor(sf::Color::White);
				m_selectedItem--;
			}

			
		}
		else
			if (m_text[1].getGlobalBounds().contains(sf::Vector2f(curserPos))) {
				if (m_selectedItem == 0) {
					m_text[1].setOutlineColor(sf::Color::Red);
					m_text[0].setOutlineColor(sf::Color::White);
					m_selectedItem ++;
			}

			}
			
	

	}




void Menu::Move_Up()
{
	if (m_selectedItem -1 >=0)
	{
		
		m_text[m_selectedItem].setOutlineColor(sf::Color::White);//the quit button color
		//m_text[m_selectedItem].setOutlineThickness(1);
		m_selectedItem--;
		//m_text[m_selectedItem].setOutlineThickness(3);
		m_text[m_selectedItem].setOutlineColor(sf::Color::Green);//the play button color
	}
}
void Menu::Move_Down()
{
	if (m_selectedItem + 1 < MAX_NUMBER_OF_ITEM)
	{
		
		m_text[m_selectedItem].setOutlineColor(sf::Color::White);//the quit button color
		//m_text[m_selectedItem].setOutlineThickness(1);
		m_selectedItem++;
		//m_text[m_selectedItem].setColor(sf::Color::Red);
		//m_text[m_selectedItem].setOutlineThickness(3);
		m_text[m_selectedItem].setOutlineColor(sf::Color::Red);//the play button color
	}
}