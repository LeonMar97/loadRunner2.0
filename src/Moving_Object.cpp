#include "Moving_Object.h"

void Moving_Object::effect(void* key)
{
	switch (*(sf::Keyboard::Key*)key)
	{
	case sf::Keyboard::Key::Up:
			m_Elemnt_Of_Game.move(0,  - m_Elemnt_Of_Game.getLocalBounds().height);
		break;
	case sf::Keyboard::Key::Down:
			m_Elemnt_Of_Game.move(0, m_Elemnt_Of_Game.getLocalBounds().height);
		break;
	case sf::Keyboard::Key::Left:
			m_Elemnt_Of_Game.move(-m_Elemnt_Of_Game.getLocalBounds().width,0);
		break;
	case sf::Keyboard::Key::Right:
			m_Elemnt_Of_Game.move(m_Elemnt_Of_Game.getLocalBounds().width, 0);
		break;

	};
}
