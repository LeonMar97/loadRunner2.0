#include "Moving_Object.h"

void Moving_Object::effect(void* key, std::vector<Game_Object*>m_All_Objects[NUM_OF_OBJECTS])
{

	sf::RectangleShape floor(m_Elemnt_Of_Game);
	floor.move(0, 3.5f);

		
	sf::RectangleShape temp(m_Elemnt_Of_Game);
	switch (*(sf::Keyboard::Key*)key)
	{

	case sf::Keyboard::Key::Up:
		std::cout << "my pos is : " << this->get_loction().x << "," <<
			this->get_loction().y << std::endl;
		if (What_In_Loc(m_Elemnt_Of_Game, m_All_Objects) == pole)
			break;
		temp.move(0, -5.0f);
		if (check_movment(temp, m_All_Objects, *this))

			m_Elemnt_Of_Game.move(0, -5.0f);
			
		break;
		

	case sf::Keyboard::Key::Down:
		
		 temp.move(0, 5.0f);
		 if (What_In_Loc(m_Elemnt_Of_Game, m_All_Objects) == pole) {
			 m_Elemnt_Of_Game.move(0, m_Elemnt_Of_Game.getGlobalBounds().height*0.75);
			 break;
		 }
		if (check_movment(temp, m_All_Objects,*this))
			m_Elemnt_Of_Game.move(0, 5.0f);
		break;

	
	case sf::Keyboard::Key::Left:
		/*
		if (What_In_Loc(m_Elemnt_Of_Game, m_All_Objects) == ladder&& //cant move from ladder
			What_In_Loc(floor, m_All_Objects)!=wall)
			break;
			*/
		std::cout << "my pos is : " << this->get_loction().x << "," <<
			this->get_loction().y << std::endl;
		std::cout << "walking left : " << temp.getPosition().x << "," <<
			temp.getPosition().y << std::endl;

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
		/*
		if (What_In_Loc(m_Elemnt_Of_Game, m_All_Objects) == ladder &&//cant move from ladder
			What_In_Loc(floor, m_All_Objects) != wall)
			break;
	*/
		std::cout << "my pos is : " << this->get_loction().x << "," <<
			this->get_loction().y << std::endl;
		 temp.move(5.0f, 0);
		 
			 std::cout << "walking right : " << temp.getPosition().x << "," <<
				 temp.getPosition().y << std::endl;

		 
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
	
		//std::cout << "im a wall" << std::endl;
		return false;
		break;

	case ladder:
	
			//std::cout << "im a ladder"<<std::endl;
		if (check_ladder(cur_Loc, m_All_Objects, last_Loc))
			return true;
		else return false;
		break;
	case pole:
		
		return check_pole(m_All_Objects,last_Loc,cur_Loc);
		
		
		
		
		//case pole:if (check_pole(temp, m_All_Objects, last_loc)) {
		//	if(last_loc.getGlobalBounds().height>temp.getGlobalBounds().height)
	};

			


		
		
	
	return true;
}
//=========================================================================
bool Moving_Object::check_ladder(sf::RectangleShape& cur_Loc, std::vector<Game_Object*>m_All_Objects[],
																						Game_Object& last_Loc)
{
	 sf::RectangleShape temp(last_Loc.get_rectangle());
		char cur_Type = What_In_Loc(temp,m_All_Objects);
	/*	sf::RectangleShape floor(this->m_Elemnt_Of_Game);
		floor.move(0, m_Elemnt_Of_Game.getGlobalBounds().height);//the floor under the current elemnt
		if (What_In_Loc(floor, m_All_Objects) == wall)
		{
			//if(floor.getGlobalBounds().intersects(cur_Loc.getGlobalBounds()))
			return true;
		}
	*/
		sf::RectangleShape floor(m_Elemnt_Of_Game);
		floor.move(0, 5.0f);
		char under = What_In_Loc(floor, m_All_Objects);
		switch (cur_Type) {

			case  ladder:	
				return true;
			break;
			
			case pole:
				if (last_Loc.get_rectangle().getPosition().x <= cur_Loc.getPosition().x )
				 {
				m_Elemnt_Of_Game.move(m_Elemnt_Of_Game.getGlobalBounds().width * 1.3f, 0);
				return false;
			    }
			    if (last_Loc.get_rectangle().getPosition().x >= cur_Loc.getPosition().x)
				 {
				 m_Elemnt_Of_Game.move(-m_Elemnt_Of_Game.getGlobalBounds().width * 1.3f, 0);
				 return false;
				 }
				return true;
			break;
			
			case space:	
				if (last_Loc.get_rectangle().getPosition().y <= cur_Loc.getPosition().y &&
					(under == ladder))
					return true;
				if (last_Loc.get_rectangle().getPosition().x <= cur_Loc.getPosition().x &&
					(under == wall)) {
					m_Elemnt_Of_Game.move(m_Elemnt_Of_Game.getGlobalBounds().width*1.3f , 0);
					return false;
				}
				if (last_Loc.get_rectangle().getPosition().x >= cur_Loc.getPosition().x &&
					(under == wall)) {
					m_Elemnt_Of_Game.move(-m_Elemnt_Of_Game.getGlobalBounds().width*1.3f, 0);
					return false;
				}
				
				break;
			case money:
				 return true;
		
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
				if (m_All_Objects[i][j]->get_Type() != this->get_Type())
				return type = m_All_Objects[i][j]->get_Type();
			}
		
		}

	}
	
	return type;
}
//=====================================================================
void Moving_Object::on_Floor(std::vector<Game_Object*>m_All_Objects[])
{

	sf::RectangleShape under_Me(m_Elemnt_Of_Game);
	under_Me.move(0, 0.1f);//the floor under the current elemnt
	char under_Me_Type = What_In_Loc(under_Me, m_All_Objects);
	int key = (sf::Keyboard::Down);
	if (under_Me_Type != wall && under_Me_Type != ladder && under_Me_Type != pole)
		this->effect(&key, m_All_Objects);
	
	
}
//===================================================================

bool Moving_Object::check_pole(std::vector<Game_Object*>m_All_Objects[],
	Game_Object& last_Loc, sf::RectangleShape& cur_Loc)
{
	
	sf::RectangleShape temp(last_Loc.get_rectangle());
	if (cur_Loc.getPosition().y - last_Loc.get_rectangle().getPosition().y < 0.1f)
		return true;
	if (What_In_Loc(temp, m_All_Objects) == '-')
		return true;
	else
	{
		if (cur_Loc.getPosition().y - last_Loc.get_loction().y < 0.1f) {
			m_Elemnt_Of_Game.getTexture()->~Texture();

			return true;
		}
		m_Elemnt_Of_Game.move(0, 0.5f + m_Elemnt_Of_Game.getLocalBounds().height / 2);
;
	}
		return false;
	
}