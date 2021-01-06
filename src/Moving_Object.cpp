#include "Moving_Object.h"

void Moving_Object::effect(void* key, std::vector<Game_Object*>m_All_Objects[NUM_OF_OBJECTS])
{
	
	sf::Vector2f next_loc(m_Elemnt_Of_Game.getPosition());
	sf::RectangleShape temp(m_Elemnt_Of_Game);
	switch (*(sf::Keyboard::Key*)key)
	{
	case sf::Keyboard::Key::Up:
		temp.move(0, -5.0f);
		if(check_movment(temp,m_All_Objects,*this))
			m_Elemnt_Of_Game.move(0, -5.0f);
			
		break;
		

	case sf::Keyboard::Key::Down:
		
		 temp.move(0, 5.0f);
		if (check_movment(temp, m_All_Objects,*this))
			m_Elemnt_Of_Game.move(0, 5.0f);
		break;


	case sf::Keyboard::Key::Left:
		
		temp.move(-5.0f, 0);
		if (check_movment(temp, m_All_Objects, *this))
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
		 if (check_movment(temp, m_All_Objects, *this))
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
bool Moving_Object::check_movment(sf::RectangleShape& cur_Loc, std::vector<Game_Object*>m_All_Objects[],
																				Game_Object& last_Loc){	
	switch (What_In_Loc(cur_Loc, m_All_Objects)) {
	case wall:  
		std::cout << "im a wall" << std::endl;
		return false;
		break;

	case ladder:
		std::cout << "im a ladder"<<std::endl;
		if (check_ladder(cur_Loc, m_All_Objects, last_Loc))
			return true;
		else return false;
		break;

		//case pole:if (check_pole(temp, m_All_Objects, last_loc)) {
		//	if(last_loc.getGlobalBounds().height>temp.getGlobalBounds().height)
	};

			


		
		
	
	return true;
}
//=========================================================================
bool Moving_Object::check_ladder(sf::RectangleShape& cur_Loc, std::vector<Game_Object*>m_All_Objects[],
																						Game_Object& last_Loc)
{
	
		char cur_Type = What_In_Loc(m_Elemnt_Of_Game,m_All_Objects);
		sf::RectangleShape floor(this->m_Elemnt_Of_Game);
		floor.move(0, m_Elemnt_Of_Game.getGlobalBounds().height/2);//the floor under the current elemnt
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
				if (last_Loc.get_rectangle().getPosition().y< cur_Loc.getPosition().y||floor.getPosition().y< cur_Loc.getPosition().y)
						return true;
			break;
			};

	return false;
}
//===================================================================
//get loc and return typy
char Moving_Object::What_In_Loc(sf::RectangleShape& temp, std::vector<Game_Object*>m_All_Objects[])
{

	char type = space;
	for (int i = 0; i <NUM_OF_OBJECTS ; i++)
	{
		for (int j = 0;j < m_All_Objects[i].size();j++) {

			if (temp.getGlobalBounds().intersects(m_All_Objects[i][j]->get_rectangle().getGlobalBounds()))
			{
				return type = m_All_Objects[i][j]->get_Type();
			}
		
		}

	}
	
	return type;
}
//=====================================================================
void Moving_Object::on_Floor( std::vector<Game_Object*>m_All_Objects[])
{

	sf::RectangleShape under_Me(this->m_Elemnt_Of_Game);
	under_Me.move(0,1.5f);//the floor under the current elemnt
	char under_Me_Type = What_In_Loc(under_Me, m_All_Objects);
	int key = (sf::Keyboard::Down);
	if (under_Me_Type != wall && under_Me_Type != ladder && under_Me_Type != pole && under_Me_Type != money)
		this->effect(&key, m_All_Objects);

}
//===================================================================
