#include <cstdlib>
#include <iostream>
#include "Disappearing_Object.h"
#include <ctime>
#pragma once
class Gift :public Disappearing_Object{
public:
	//using Disappearing_Object::Disappearing_Object;
	Gift(sf::RectangleShape cur_rec, std::vector<sf::Texture*>tex,
		sf::Vector2f loction, char icon = ' ') :
		Disappearing_Object(cur_rec, (tex), (loction), (icon)) {
		//set_Sounds();
	}
	~Gift() { m_S_Buf.clear(); }
	void handleCollision(Game_Object& gameObject)override {};
	void handleCollision(Enemy& gameObject)override {};
	void handleCollision(Money& gameObject)override {};
	void handleCollision(Player& gameObject)override ;
	void handleCollision(Gift& gameObject)override {};
	bool get_Bad_Gift()const { return m_Get_Enemy; };//returns controller info new enemy needed
	bool get_time_Gift()const { return m_Plus_Time; };
private:
	bool m_Get_Enemy=false;
	bool m_Plus_Time = false;
	
	//void set_Sounds();
	std::vector<sf::Sound*>m_S_Buf;
};


