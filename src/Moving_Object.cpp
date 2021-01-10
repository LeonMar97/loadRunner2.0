#include "Moving_Object.h"

void Moving_Object::effect(void* key, std::vector<Game_Object*>m_All_Objects[NUM_OF_OBJECTS])
{
	

		
	sf::RectangleShape temp(m_Elemnt_Of_Game);
	switch (*(sf::Keyboard::Key*)key)
	{

	case sf::Keyboard::Key::Up:
		
		
		temp.move(0, -m_Elemnt_Of_Game.getGlobalBounds().height*0.1f);
		if (check_movment(temp, m_All_Objects, *this)) {
			m_Elemnt_Of_Game.move(0, -m_Elemnt_Of_Game.getGlobalBounds().height * 0.1f);
			m_Elemnt_Of_Game.setTexture(m_Tex[0]);
		}
		break;
		

	case sf::Keyboard::Key::Down:
		
		 temp.move(0, m_Elemnt_Of_Game.getGlobalBounds().height * 0.1f);
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
	change__Curr_Texture(m_All_Objects);
	
}
//=============================================================================
//check what in the next loc user pressed
bool Moving_Object::check_movment(sf::RectangleShape& after_Click, std::vector<Game_Object*>m_All_Objects[],
																				Game_Object& before_Click){	
	switch (What_In_Loc(after_Click, m_All_Objects)) {
	case wall:  
	
		return false;
		break;

	case ladder:
		return (check_ladder(after_Click, m_All_Objects, before_Click));
	case pole:
		return check_pole(m_All_Objects,before_Click,after_Click);
	case space:
		return check_space(m_All_Objects, before_Click, after_Click);
		
	};
	
	return true;
}
//=========================================================================
//check if next loc is ladder,last_loc before click ,cur_loc after click
bool Moving_Object::check_ladder(sf::RectangleShape& after_Click, std::vector<Game_Object*>m_All_Objects[],
																						Game_Object& before_Click)
{
	 sf::RectangleShape temp(before_Click.get_rectangle());
		char cur_Type = What_In_Loc(temp,m_All_Objects);
	
		sf::RectangleShape floor(m_Elemnt_Of_Game);
		floor.move(0, m_Elemnt_Of_Game.getGlobalBounds().height * 0.1f);
		char under = What_In_Loc(floor, m_All_Objects);//check whar under me
		switch (cur_Type) {

			case  ladder:
				if ((under != wall) &&( before_Click.get_rectangle().getPosition().y - after_Click.getPosition().y > 0.1f||
					after_Click.getPosition().y - before_Click.get_rectangle().getPosition().y > 0.1f)) {
					move_to_center(m_All_Objects);
				}
				return true;
			    break;
			
			case pole:
				return true;
			    break;
			
			case space:	
				
				if (before_Click.get_rectangle().getPosition().y <= after_Click.getPosition().y &&
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
	{
		return;
	}
	if ((under_Me_Type) == pole)//if we are on pole dont drop
	{
		m_Elemnt_Of_Game.move(0, m_Elemnt_Of_Game.getGlobalBounds().height * 0.5f);
		
		return;
	}
	if ((under_Me_Type != wall && under_Me_Type != ladder))
		this->effect(&key, m_All_Objects);
	
}
//===================================================================
bool Moving_Object::check_pole(std::vector<Game_Object*>m_All_Objects[],
	Game_Object& before_Click, sf::RectangleShape& after_Click)
{
	
	sf::RectangleShape temp(before_Click.get_rectangle());
	if (after_Click.getPosition().y - before_Click.get_loction().y > 0.1f){
		after_Click.move(0, m_Elemnt_Of_Game.getGlobalBounds().height * 0.6);
		if (What_In_Loc(after_Click, m_All_Objects) != wall) {
			m_Elemnt_Of_Game.move(0, m_Elemnt_Of_Game.getGlobalBounds().height * 0.6);
			
			return false;
		}
	}
	if(What_In_Loc(temp, m_All_Objects) == ladder)
	{
		
		return true;
	}
	if (What_In_Loc(temp,m_All_Objects)==pole)
	{
		return true;
	}
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
				if (m_All_Objects[i][j]->get_Type() != this->get_Type()) {
					if (m_All_Objects[i][j]->get_Type() == ladder)
						m_Elemnt_Of_Game.setPosition(m_All_Objects[i][j]->get_loction().x, m_Elemnt_Of_Game.getPosition().y);
					
				}
			}

		}

	}
}
//---------------------------------------------------------------------
///function check going in to air
bool Moving_Object::check_space(std::vector<Game_Object*>m_All_Objects[],
	Game_Object& before_Click, sf::RectangleShape& after_Click)
{
	sf::RectangleShape temp_loc(before_Click.get_rectangle());
	switch (What_In_Loc(temp_loc, m_All_Objects)) {
	case ladder:
		return check_ladder(after_Click, m_All_Objects, before_Click);
	case pole:
		return check_pole( m_All_Objects, before_Click, after_Click);
	};
	return true;
}
//====================================================================
void Moving_Object::change__Curr_Texture(std::vector<Game_Object*>m_All_Objects[])
{
	if (What_In_Loc(m_Elemnt_Of_Game, m_All_Objects) == pole)
		m_Elemnt_Of_Game.setTexture(m_Tex[1]);
	else
		m_Elemnt_Of_Game.setTexture(m_Tex[0]);
}