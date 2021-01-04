#include "Moving_Object.h"

void Moving_Object::effect(void* key, std::vector<Game_Object*>& m_All_Objects)
{
	sf::Vector2f next_loc(m_Elemnt_Of_Game.getPosition());
	switch (*(sf::Keyboard::Key*)key)
	{
	case sf::Keyboard::Key::Up:
		next_loc.x = m_Elemnt_Of_Game.getPosition().x,
			next_loc.y=m_Elemnt_Of_Game.getPosition().y - m_Elemnt_Of_Game.getLocalBounds().height;
		
		if(check_movment(next_loc,m_All_Objects,m_Elemnt_Of_Game.getPosition()))
			m_Elemnt_Of_Game.move(0,  - m_Elemnt_Of_Game.getLocalBounds().height);
			
		break;


	case sf::Keyboard::Key::Down:
		 next_loc.x=m_Elemnt_Of_Game.getPosition().x,
			 next_loc.y=m_Elemnt_Of_Game.getPosition().y +m_Elemnt_Of_Game.getLocalBounds().height;
		if (check_movment(next_loc, m_All_Objects, m_Elemnt_Of_Game.getPosition()))
			m_Elemnt_Of_Game.move(0, m_Elemnt_Of_Game.getLocalBounds().height);
		break;


	case sf::Keyboard::Key::Left:
		next_loc.x=m_Elemnt_Of_Game.getPosition().x - m_Elemnt_Of_Game.getLocalBounds().width,
			next_loc.y=m_Elemnt_Of_Game.getPosition().y ;
		if (check_movment(next_loc, m_All_Objects, m_Elemnt_Of_Game.getPosition()))
			m_Elemnt_Of_Game.move(-(m_Elemnt_Of_Game.getLocalBounds().width), 0);
		break;
			
	case sf::Keyboard::Key::Right:
		 next_loc.x=m_Elemnt_Of_Game.getPosition().x + m_Elemnt_Of_Game.getLocalBounds().width,
			 next_loc.y=m_Elemnt_Of_Game.getPosition().y;
		if (check_movment(next_loc, m_All_Objects, m_Elemnt_Of_Game.getPosition()))
			m_Elemnt_Of_Game.move((m_Elemnt_Of_Game.getLocalBounds().width), 0);
		break;

	};
}
//=============================================================================
bool Moving_Object::check_movment(sf::Vector2f& cur_loc, std::vector<Game_Object*>& m_All_Objects,sf::Vector2f last_loc)
{

	for (int i = 0; i < m_All_Objects.size() - 1; i++)
	{
		//.intersects(m_All_Objects[i]->get_rectangle()
		if (fabs(cur_loc.x - (m_All_Objects[i]->get_loction().x)) < 10.1f &&
			fabs(cur_loc.y - (m_All_Objects[i]->get_loction().y)) < 10.1f)
		{
			switch (m_All_Objects[i]->get_Type()) {
			case wall:
				return false;
				break;

			case ladder:
				if (!check_ladder(cur_loc, m_All_Objects,last_loc))
					return false;
				else return true;
				break;
			}
		}
	}
	return true;
}
//=========================================================================
bool Moving_Object::check_ladder(sf::Vector2f& afterclick_Loc, std::vector<Game_Object*>& m_All_Objects,sf::Vector2f beforeclick_Loc)
{
	int player_place=m_All_Objects.size() - 1;
	for (int i = 0; i < m_All_Objects.size(); i++)
	{
		if (fabs(afterclick_Loc.x - (m_All_Objects[i]->get_loction().x)) < 10.1f &&
			fabs(afterclick_Loc.y - (m_All_Objects[i]->get_loction().y - m_All_Objects[i]->get_rectangle().getGlobalBounds().height)) < 10.1f)
		{
			if (m_All_Objects[i]->get_Type() == '#')
			{
				return true;
			}
			else {

				if (m_All_Objects[i]->get_Type() == 'H')
				{
					if(What_In_Loc(beforeclick_Loc,m_All_Objects)!='@')
					return true;
				}
				
				
					
			}
		}

	}

	return false;
}
//===================================================================
//get loc and return typy
char Moving_Object::What_In_Loc(sf::Vector2f& loc, std::vector<Game_Object*>& m_All_Objects)
{
	for (int i = 0; i < m_All_Objects.size() ; i++)
	{
		if (fabs(loc.x - (m_All_Objects[i]->get_loction().x)) < 10.1f &&
			fabs(loc.y - (m_All_Objects[i]->get_loction().y )) < 10.1f)
		{
			return m_All_Objects[i]->get_Type();
		}
	}
	
}