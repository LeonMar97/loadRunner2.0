#include "Moving_Object.h"

void Moving_Object::effect(void* key, std::vector<Game_Object*>& m_All_Objects)
{
	
	sf::Vector2f next_loc(m_Elemnt_Of_Game.getPosition());
	sf::RectangleShape temp(m_Elemnt_Of_Game);
	switch (*(sf::Keyboard::Key*)key)
	{
	case sf::Keyboard::Key::Up:
		temp.move(0, -5.0f);
		if(check_movment(temp,m_All_Objects,m_Elemnt_Of_Game))
			m_Elemnt_Of_Game.move(0, -5.0f);
			
		break;
		

	case sf::Keyboard::Key::Down:
		
		 temp.move(0, 5.0f);
		if (check_movment(temp, m_All_Objects, m_Elemnt_Of_Game))
			m_Elemnt_Of_Game.move(0, 5.0f);
		break;


	case sf::Keyboard::Key::Left:
		
		temp.move(-5.0f, 0);
		if (check_movment(temp, m_All_Objects, m_Elemnt_Of_Game))
		{
			if (direction){
				m_Elemnt_Of_Game.scale(-1, 1);
			direction = false;
		    }
			m_Elemnt_Of_Game.move(-5.0f, 0);
			
		}
		break;
			
	case sf::Keyboard::Key::Right:
		
		 temp.move(5.0f, 0);
		 if (check_movment(temp, m_All_Objects, m_Elemnt_Of_Game))
		 {
			 if (!direction) {
				
				 m_Elemnt_Of_Game.scale(-1, 1);
				 direction = true;
			 }
			 m_Elemnt_Of_Game.move(5.0f, 0);
		 }
		break;

	};

}
//=============================================================================
bool Moving_Object::check_movment(sf::RectangleShape &temp, std::vector<Game_Object*>& m_All_Objects,
																				sf::RectangleShape&last_loc)
{
	
		
	switch (What_In_Loc(temp, m_All_Objects)) {
	case wall:
		return false;
		break;

	case ladder:
		if (check_ladder(temp, m_All_Objects, last_loc.getPosition()))
			return true;
		else return false;
		break;

		//case pole:if (check_pole(temp, m_All_Objects, last_loc)) {
		//	if(last_loc.getGlobalBounds().height>temp.getGlobalBounds().height)
	};

			


		
		
	
	return true;
}
//=========================================================================
bool Moving_Object::check_ladder(sf::RectangleShape& temp, std::vector<Game_Object*>& m_All_Objects,sf::Vector2f beforeclick_Loc)
{
	int player_place=m_All_Objects.size() - 1;
	
	{
		sf::RectangleShape last(m_All_Objects[player_place]->get_rectangle());
		char cur_Type = What_In_Loc(last, m_All_Objects);
		char next_Type = What_In_Loc(temp, m_All_Objects);

		sf::RectangleShape floor(m_Elemnt_Of_Game);
		floor.move(0, m_All_Objects[player_place]->get_rectangle().getGlobalBounds().height/2);
			if (What_In_Loc(floor, m_All_Objects) == wall)
			{	
				return true;
			}
			
			if (cur_Type == ladder && next_Type == ladder)
			{
				return true;
			}
			if (cur_Type == wall )
			{
				return true;
			}
			if (cur_Type == pole && next_Type == ladder)
			{
				return true;
			}
			if (cur_Type == space && next_Type == ladder)
			{
				if (beforeclick_Loc.y < temp.getPosition().y)             
					
					return true;
			}
			


			
			
			
			

	}

	return false;
}
//===================================================================
//get loc and return typy
char Moving_Object::What_In_Loc(sf::RectangleShape&temp, std::vector<Game_Object*>& m_All_Objects)
{
	char type = space;
	for (int i = 0; i < m_All_Objects.size()-1 ; i++)
	{
	
		if(temp.getGlobalBounds().intersects(m_All_Objects[i]->get_rectangle().getGlobalBounds()))
		{
			return type= m_All_Objects[i]->get_Type();
		}
	}
	
	return space;
}
//===================================================================
