#pragma once
#include "Menu.h"


Menu::Menu()
{
	
	m_font.loadFromFile("Love America.ttf");
	

	m_text[0].setFont(m_font);
	m_text[0].setColor(sf::Color::Blue);
	m_text[0].setOutlineThickness(5);
	m_text[0].setOutlineColor(sf::Color::Red);
	m_text[0].setString("Play");
	m_text[0].setPosition(sf::Vector2f(1980 / 2, 1080/ (MAX_NUMBER_OF_ITEM + 1) * 1));

    m_text[1].setFont(m_font);
	m_text[1].setColor(sf::Color::Blue);
	m_text[1].setString("Quit");
	m_text[1].setPosition(sf::Vector2f(1980 / 2, 1080 / (MAX_NUMBER_OF_ITEM + 1) * 2));
	m_selectedItem = 0;
	sf::Texture* background = new sf::Texture();
	background->loadFromFile("bg_23.png");
	m_Menu_Background.setTexture(*background);
}

void Menu::draw(sf::RenderWindow& window)
{
	bool in_menu =true;
	sf::Event event;
	while (in_menu)
	{
		window.clear();
		window.draw(m_Menu_Background);
		for (int i = 0; i < MAX_NUMBER_OF_ITEM; i++)
		{
			window.draw(m_text[i]);
		}
		window.display();
		while (window.pollEvent(event))
		{
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
					switch (Get_Pressed())
					{
					case 0:
						in_menu = false;
						continue;
					
					case 1:
						in_menu = false;
						window.close();
						break;
					}
			
				};
				break;
			case sf::Event::Closed:
				window.close();
				break;
			};
		}
	}

}

void Menu::Move_Up()
{
	if (m_selectedItem -1 >=0)
	{
		
		m_text[m_selectedItem].setOutlineColor(sf::Color::White);
		m_text[m_selectedItem].setOutlineThickness(1);
		m_selectedItem--;
		m_text[m_selectedItem].setOutlineThickness(5);
		m_text[m_selectedItem].setOutlineColor(sf::Color::Red);
	}
}
void Menu::Move_Down()
{
	if (m_selectedItem + 1 < MAX_NUMBER_OF_ITEM)
	{
		
		m_text[m_selectedItem].setOutlineColor(sf::Color::White);
		m_text[m_selectedItem].setOutlineThickness(1);
		m_selectedItem++;
		//m_text[m_selectedItem].setColor(sf::Color::Red);
		m_text[m_selectedItem].setOutlineThickness(5);
		m_text[m_selectedItem].setOutlineColor(sf::Color::Red);
	}
}