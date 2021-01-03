#include "Moving_Object.h"

void Moving_Object::effect(void* key)
{
	
	sf::RectangleShape temp;
	temp.setSize(m_Elemnt_Of_Game.getSize());
	temp.setPosition(m_Elemnt_Of_Game.getPosition());
	switch (*(sf::Keyboard::Key*)key)
	{
	case sf::Keyboard::Key::Up:
		temp.setPosition(temp.getPosition().x, temp.getPosition().y - temp.getGlobalBounds().height);
		
		{
			m_Elemnt_Of_Game.setPosition(temp.getPosition());

		}
		break;

	case sf::Keyboard::Key::Down:
		temp.setPosition(temp.getPosition().x, temp.getPosition().y + temp.getGlobalBounds().height);
		
		{

			m_Elemnt_Of_Game.setPosition(temp.getPosition());

		}
		break;
	case sf::Keyboard::Key::Left:
		temp.setPosition(temp.getPosition().x - temp.getGlobalBounds().width, temp.getPosition().y);

		
		{

			m_Elemnt_Of_Game.setPosition(temp.getPosition());
		}
		break;
	case sf::Keyboard::Key::Right:
		temp.setPosition(temp.getPosition().x + temp.getGlobalBounds().width, temp.getPosition().y);
		
		{

			m_Elemnt_Of_Game.setPosition(temp.getPosition());


		}
		break;

	};
}
