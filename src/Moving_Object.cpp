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
		std::cout << "im a wall" << std::endl;
		return false;
		break;

	case ladder:
		std::cout << "im a ladder"<<std::endl;
		if (check_ladder( temp, m_All_Objects, last_loc))
			return true;
		else return false;
		break;

		//case pole:if (check_pole(temp, m_All_Objects, last_loc)) {
		//	if(last_loc.getGlobalBounds().height>temp.getGlobalBounds().height)
	};

			


		
		
	
	return true;
}
//=========================================================================
bool Moving_Object::check_ladder(sf::RectangleShape& cur_Loc,std::vector<Game_Object*>& m_All_Objects,
																						sf::RectangleShape& last_Loc)
{
	
		char cur_Type = What_In_Loc(last_Loc,m_All_Objects);

		sf::RectangleShape floor(m_Elemnt_Of_Game);
		floor.move(0, m_All_Objects[m_All_Objects.size()-1]->get_rectangle().getGlobalBounds().height/2);
		if (What_In_Loc(floor, m_All_Objects) == wall)
		{
			return true;
		}
	
		switch (cur_Type) {

			case  ladder:	// if im standing on a ladder
				return true;
			break;
			
			case pole:
				return true;
			break;
			
			case space:	
				if (last_Loc.getPosition().y < cur_Loc.getPosition().y||floor.getPosition().y< cur_Loc.getPosition().y)
						return true;
			break;
			};

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
