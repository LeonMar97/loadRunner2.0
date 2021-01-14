#include "Moving_Object.h"
class Player;
void Moving_Object::move_Object(sf::Vector2f& Direction, sf::Time delta_time, std::vector<Game_Object*>m_All_Objects[NUM_OF_OBJECTS])
{



	sf::RectangleShape temp(m_Elemnt_Of_Game);
	if ((int)Direction.y == 1 && ((int)Direction.x == -1 || (int)Direction.x == 1)) {
		handle_dig(*this, m_All_Objects[walls], Direction, delta_time);
		change__Curr_Texture(m_All_Objects, Direction);
		return;
	}
	float size = (m_Elemnt_Of_Game.getTexture()->getSize().x) / 3;
	
		temp.move(Direction * size * delta_time.asSeconds());
		if (check_movment(temp, m_All_Objects, *this)) {

			m_Elemnt_Of_Game.move(Direction * size * delta_time.asSeconds());

		}
	
	
	handleCollision_moving(*this, m_All_Objects);



	change__Curr_Texture(m_All_Objects, Direction);

}
//=============================================================================
//check what in the next loc user pressed
bool Moving_Object::check_movment(sf::RectangleShape& after_Click, std::vector<Game_Object*>m_All_Objects[],
	Game_Object& before_Click) {
	switch (What_In_Loc(after_Click, m_All_Objects)) {
	case wall:

		return false;
	case ladder:
		return (check_ladder(after_Click, m_All_Objects, before_Click));
	case pole:
		return check_pole(m_All_Objects, before_Click, after_Click);
	case space:
		return check_space(m_All_Objects, before_Click, after_Click);

	};


	return true;//return true if enemy score or player
}
//=========================================================================
//check if next loc is ladder,last_loc before click ,cur_loc after click
bool Moving_Object::check_ladder(sf::RectangleShape& after_Click, std::vector<Game_Object*>m_All_Objects[],
	Game_Object& before_Click)
{
	sf::RectangleShape temp(before_Click.get_rectangle());
	char cur_Type = What_In_Loc(temp, m_All_Objects);

	sf::RectangleShape floor(m_Elemnt_Of_Game);
	floor.move(0, m_Elemnt_Of_Game.getGlobalBounds().height * 0.1f);
	char under = What_In_Loc(floor, m_All_Objects);//check whar under me
	switch (cur_Type) {

	case  ladder:
		if ((under != wall) && (before_Click.get_rectangle().getPosition().y - after_Click.getPosition().y > 0.1f ||
			after_Click.getPosition().y - before_Click.get_rectangle().getPosition().y > 0.1f)) {
			move_to_center_ladder(m_All_Objects[ladders]);
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
		if (under == wall || under == pole) {
			return true;
		}

		break;


	};

	return false;
}
//===================================================================
//get loc and return typy
char Moving_Object::What_In_Loc(sf::RectangleShape& temp, std::vector<Game_Object*>m_All_Objects[])
{

	char type = space;
	for (int i = 0; i < NUM_OF_OBJECTS; i++)
	{
		for (int j = 0; j < m_All_Objects[i].size(); j++) {

			if (temp.getGlobalBounds().intersects(m_All_Objects[i][j]->get_rectangle().getGlobalBounds()))
			{
				if (m_All_Objects[i][j]->get_Type() != this->get_Type()) {
					if (m_All_Objects[i][j]->get_Print_Me() || this->get_loction().y > 760.f || this->get_loction().x > 1420.f || this->get_loction().x < 370.f)
						return type = m_All_Objects[i][j]->get_Type();

				}
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
	//int key = (sf::Keyboard::Down);

	sf::Vector2f key(0, m_Elemnt_Of_Game.getGlobalBounds().height * 0.1f);
	if (What_In_Loc(m_Elemnt_Of_Game, m_All_Objects) == pole)//if we are on pole dont drop
	{
		return;
	}
	if ((under_Me_Type) == pole)//if we are on pole dont drop
	{
		m_Elemnt_Of_Game.move(0, m_Elemnt_Of_Game.getGlobalBounds().height * 0.1f);
		move_to_center_pole(m_All_Objects[poles]);
		return;
	}
	if ((under_Me_Type != wall && under_Me_Type != ladder))
		m_Elemnt_Of_Game.move(0, key.y);

}
//===================================================================
bool Moving_Object::check_pole(std::vector<Game_Object*>m_All_Objects[],
	Game_Object& before_Click, sf::RectangleShape& after_Click)
{

	sf::RectangleShape temp(before_Click.get_rectangle());
	if (after_Click.getPosition().y - before_Click.get_loction().y > 0.1f) {
		after_Click.move(0, (m_Elemnt_Of_Game.getGlobalBounds().height * 0.4f));
		if (What_In_Loc(after_Click, m_All_Objects) != wall) {
			m_Elemnt_Of_Game.move(0, m_Elemnt_Of_Game.getGlobalBounds().height * 0.4f);

			return false;
		}
	}


	move_to_center_pole(m_All_Objects[poles]);
	return true;
}
//-------------------------------------------------------------------------------
//move object to the center of ladder or pole
void Moving_Object::move_to_center_ladder(std::vector<Game_Object*>& m_All_Objects)
{


	for (int j = 0; j < m_All_Objects.size(); j++) {

		if (m_Elemnt_Of_Game.getGlobalBounds().intersects(m_All_Objects[j]->get_rectangle().getGlobalBounds()))
		{
			if (m_All_Objects[j]->get_Type() != this->get_Type()) {
				if (m_All_Objects[j]->get_Type() == ladder)
					m_Elemnt_Of_Game.setPosition(m_All_Objects[j]->get_loction().x, m_Elemnt_Of_Game.getPosition().y);

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
		return check_pole(m_All_Objects, before_Click, after_Click);
	};
	return true;
}
//====================================================================
void Moving_Object::change__Curr_Texture(std::vector<Game_Object*>m_All_Objects[], sf::Vector2f& Direction)
{
	if (Direction.x == 1 && m_direction == left) {
		m_Elemnt_Of_Game.setScale(1, 1);
		m_direction = !m_direction;
	}
	if (Direction.x == -1 && m_direction == right)
	{
		m_Elemnt_Of_Game.setScale(-1, 1);
		m_direction = !m_direction;
	}

	if (What_In_Loc(m_Elemnt_Of_Game, m_All_Objects) == pole)
		m_Elemnt_Of_Game.setTexture(m_Tex[1]);
	else
		m_Elemnt_Of_Game.setTexture(m_Tex[0]);
}
//---------------------------------------------------------------------
//move object to center of pole
void Moving_Object::move_to_center_pole(std::vector<Game_Object*>& m_All_Objects)
{

	for (int j = 0; j < m_All_Objects.size(); j++) {

		if (m_Elemnt_Of_Game.getGlobalBounds().intersects(m_All_Objects[j]->get_rectangle().getGlobalBounds()))
		{
			if (m_All_Objects[j]->get_Type() != this->get_Type()) {
				if (m_All_Objects[j]->get_Type() == pole)
					m_Elemnt_Of_Game.setPosition(m_Elemnt_Of_Game.getPosition().x, m_All_Objects[j]->get_loction().y);

			}
		}

	}


}
//==========================================================================
void Moving_Object::handleCollision_moving(Game_Object& me, std::vector<Game_Object*>m_All_Objects[])
{
	for (int i = moneys; i < NUM_OF_OBJECTS; i++)
	{
		for (int j = 0; j < m_All_Objects[i].size(); j++) {

			if (me.get_rectangle().getGlobalBounds().intersects(m_All_Objects[i][j]->get_rectangle().getGlobalBounds()))
			{
				me.handleCollision(*m_All_Objects[i][j]);
			}

		}

	}
}
//========================================================================
void Moving_Object::handle_dig
(Game_Object& me, std::vector<Game_Object*>& m_All_Objects, sf::Vector2f& Direction, sf::Time delta_time)
{
	float size = (m_Elemnt_Of_Game.getTexture()->getSize().x) / 3;
	sf::RectangleShape temp(me.get_rectangle());
	temp.move((Direction.x * m_Elemnt_Of_Game.getGlobalBounds().width) * 2, m_Elemnt_Of_Game.getGlobalBounds().height);
	for (int j = 0; j < m_All_Objects.size(); j++) {

		if (temp.getGlobalBounds().intersects(m_All_Objects[j]->get_rectangle().getGlobalBounds()))
		{
			me.handleCollision(*m_All_Objects[j]);
		}

	}


}