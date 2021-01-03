#include "Moving_Object.h"

void Moving_Object::effect(void* key)
{
	//key = (sf::Keyboard::Key*)key;
	sf::RectangleShape temp;
	temp.setSize(m_Elemnt_Of_Game.getSize());
	temp.setPosition(m_Elemnt_Of_Game.getPosition());
	switch (*(sf::Keyboard::Key*)key)
	{
	case sf::Keyboard::Key::Up:
		temp.setPosition(temp.getPosition().x, temp.getPosition().y - temp.getGlobalBounds().height);
		//if (location_valid(temp))
		{
			m_Elemnt_Of_Game.setPosition(temp.getPosition());

		}
		break;

	case sf::Keyboard::Key::Down:
		temp.setPosition(temp.getPosition().x, temp.getPosition().y + temp.getGlobalBounds().height);
		//if (location_valid(temp))
		{

			m_Elemnt_Of_Game.setPosition(temp.getPosition());

		}
		break;
	case sf::Keyboard::Key::Left:
		temp.setPosition(temp.getPosition().x - temp.getGlobalBounds().width, temp.getPosition().y);

		//if (location_valid(temp))
		{

			m_Elemnt_Of_Game.setPosition(temp.getPosition());
		}
		break;
	case sf::Keyboard::Key::Right:
		temp.setPosition(temp.getPosition().x + temp.getGlobalBounds().width, temp.getPosition().y);
		//if (location_valid(temp))
		{

			m_Elemnt_Of_Game.setPosition(temp.getPosition());


		}
		break;

	};
}