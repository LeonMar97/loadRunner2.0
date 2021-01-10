#include "Moving_Object.h"

void Moving_Object::effect(void* key, std::vector<Game_Object*>m_All_Objects[NUM_OF_OBJECTS])
{
	sf::RectangleShape floor(m_Elemnt_Of_Game);
	floor.move(0, m_Elemnt_Of_Game.getGlobalBounds().height * 0.75);

		
	sf::RectangleShape temp(m_Elemnt_Of_Game);
	switch (*(sf::Keyboard::Key*)key)
	{

	case sf::Keyboard::Key::Up:
		
		if (What_In_Loc(m_Elemnt_Of_Game, m_All_Objects) == pole)
			break;
		temp.move(0, -m_Elemnt_Of_Game.getGlobalBounds().height*0.1f);
		if (check_movment(temp, m_All_Objects, *this)) {
			m_Elemnt_Of_Game.move(0, -m_Elemnt_Of_Game.getGlobalBounds().height * 0.1f);
			m_Elemnt_Of_Game.setTexture(m_Tex[0]);
		}
		break;
		

	case sf::Keyboard::Key::Down:
		
		 temp.move(0, m_Elemnt_Of_Game.getGlobalBounds().height * 0.1f);
		/* if (What_In_Loc(m_Elemnt_Of_Game, m_All_Objects) == pole) {
			 m_Elemnt_Of_Game.move(0, m_Elemnt_Of_Game.getGlobalBounds().height*0.75);
			 break;
		 }
		 */
		 
		 if (check_movment(temp, m_All_Objects, *this)) {
			 m_Elemnt_Of_Game.move(0,m_Elemnt_Of_Game.getGlobalBounds().height * 0.1f);
			 m_Elemnt_Of_Game.setTexture(m_Tex[0]);
		 }
		break;

	
	case sf::Keyboard::Key::Left:
		temp.move(-m_Elemnt_Of_Game.getGlobalBounds().width*0.2f, 0);
		if (check_movment(temp, m_All_Objects, *this))
		{
			if (direction){
				m_Elemnt_Of_Game.scale(-1, 1);
			direction = false;
		    }
			m_Elemnt_Of_Game.move(-m_Elemnt_Of_Game.getGlobalBounds().width * 0.2f, 0);
			
		}
		break;
			
	case sf::Keyboard::Key::Right:
		
		 temp.move(m_Elemnt_Of_Game.getGlobalBounds().width * 0.2f, 0);
		 if (check_movment(temp, m_All_Objects, *this))
		 {
		
			 if (!direction) {
				
				 m_Elemnt_Of_Game.scale(-1, 1);
				 direction = true;
			 }
			 m_Elemnt_Of_Game.move(m_Elemnt_Of_Game.getGlobalBounds().width * 0.2f, 0);
			 
		 }
		break;

	};

}
//=============================================================================
//check what in the next loc user pressed
bool Moving_Object::check_movment(sf::RectangleShape& cur_Loc, std::vector<Game_Object*>m_All_Objects[],
																				Game_Object& last_Loc){	
	switch (What_In_Loc(cur_Loc, m_All_Objects)) {
	case wall:  
	
		return false;
		break;

	case ladder:
		if (check_ladder(cur_Loc, m_All_Objects, last_Loc))
			return true;
		else return false;
		break;
	case pole:
		
		return check_pole(m_All_Objects,last_Loc,cur_Loc);
		
		
	};
	
	return true;
}
//=========================================================================
//check if next loc is ladder
bool Moving_Object::check_ladder(sf::RectangleShape& cur_Loc, std::vector<Game_Object*>m_All_Objects[],
																						Game_Object& last_Loc)
{
	 sf::RectangleShape temp(last_Loc.get_rectangle());
		char cur_Type = What_In_Loc(temp,m_All_Objects);
	
		sf::RectangleShape floor(m_Elemnt_Of_Game);
		floor.move(0, m_Elemnt_Of_Game.getGlobalBounds().height * 0.1f);
		char under = What_In_Loc(floor, m_All_Objects);//check whar under me
		switch (cur_Type) {

			case  ladder:
				if ((under != wall) &&( last_Loc.get_rectangle().getPosition().y - cur_Loc.getPosition().y > 0.1f||
					cur_Loc.getPosition().y - last_Loc.get_rectangle().getPosition().y > 0.1f)) {
					move_to_center(m_All_Objects);
				}
				return true;
			    break;
			
			case pole:
				return true;
			    break;
			
			case space:	
				
				if (last_Loc.get_rectangle().getPosition().y <= cur_Loc.getPosition().y &&
					(under == ladder))
					return true;
				if (under == wall||under==pole) {
					return true;
				}
				
				break;
			case money:
				 return true;
			case smart:
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
	under_Me.move(0, m_Elemnt_Of_Game.getGlobalBounds().height * 0.1f);//the floor under the current elemnt
	char under_Me_Type = What_In_Loc(under_Me, m_All_Objects);
	int key = (sf::Keyboard::Down);
	if (What_In_Loc(m_Elemnt_Of_Game, m_All_Objects) == pole)//if we are on pole dont drop
		return;
	if ((under_Me_Type != wall && under_Me_Type != ladder && under_Me_Type != pole))
		this->effect(&key, m_All_Objects);
	
}
//===================================================================

bool Moving_Object::check_pole(std::vector<Game_Object*>m_All_Objects[],
	Game_Object& last_Loc, sf::RectangleShape& cur_Loc)
{
	/*
	sf::RectangleShape temp(last_Loc.get_rectangle());
	if (cur_Loc.getPosition().y - last_Loc.get_rectangle().getPosition().y <0.1f) {
		m_Elemnt_Of_Game.setTexture(this->m_Tex[1]);
		m_Elemnt_Of_Game.move(0, 10.5f + m_Elemnt_Of_Game.getLocalBounds().height / 2);
		//move_to_center(m_All_Objects);
		return false;
	}
	if (What_In_Loc(temp, m_All_Objects) == pole) {

		return true;
	}
	else
	{
		m_Elemnt_Of_Game.setTexture(this->m_Tex[1]);
		m_Elemnt_Of_Game.move(0, 0.5f+ m_Elemnt_Of_Game.getLocalBounds().height /2);
		return false;
		//move_to_center(m_All_Objects);
		
	}
	*/
	sf::RectangleShape temp(cur_Loc);
	temp.move(0, 0.5f);
	//if (cur_Loc.getPosition().y - last_Loc.get_rectangle().getPosition().y > 0.1f && What_In_Loc(cur_Loc, m_All_Objects) == space)
	if (What_In_Loc(temp,m_All_Objects)==pole)
	{
		m_Elemnt_Of_Game.setTexture(this->m_Tex[1]);

		m_Elemnt_Of_Game.move(0, m_Elemnt_Of_Game.getLocalBounds().height / 4);
	}
	if(What_In_Loc(cur_Loc,m_All_Objects)==space)
	m_Elemnt_Of_Game.setTexture(this->m_Tex[1]);
		return true;
	
}
//-------------------------------------------------------------------------------
//move object to the center of ladder or pole
void Moving_Object::move_to_center(std::vector<Game_Object*>m_All_Objects[])
{
	for (int i = 0; i < NUM_OF_OBJECTS; i++)
	{
		for (int j = 0; j < m_All_Objects[i].size(); j++) {

			if (m_Elemnt_Of_Game.getGlobalBounds().intersects(m_All_Objects[i][j]->get_rectangle().getGlobalBounds()))
			{
				if (m_All_Objects[i][j]->get_Type() != this->get_Type())
					m_Elemnt_Of_Game.setPosition(m_All_Objects[i][j]->get_loction().x,m_Elemnt_Of_Game.getPosition().y);
			}

		}

	}
}