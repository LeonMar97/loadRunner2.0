#include <cstdlib>
#include <iostream>
#include "Moving_Object.h"
#include"Textures.h"
#pragma once
class Player :public Moving_Object {
//--------------public--------functions-----------------------//
public:
	//using Moving_Object::Moving_Object;
	Player(sf::RectangleShape cur_rec, sf::Vector2f loction) :
		Moving_Object(cur_rec,(Textures::instance().get_Textures(players_T)),(loction),(player)){
	}

	void setscore(int);
	int getscore()const;
	int getlives()const;
	void setlives(int);
	void effect(void* DeltaTime, std::vector<Game_Object*>m_All_Objects[NUM_OF_OBJECTS])override;
	sf::Vector2f dirFromKey();
	void handleCollision(Game_Object& gameObject) override;
	void handleCollision(Money& gameObject)override;
	void handleCollision(Enemy& gameObject)override;
	void handleCollision(Player& gameObject)override {};
	void handleCollision(Gift& gameObject)override {};
	void handleCollision(Wall& gameObject)override;
	void set_hit(bool);
	bool get_hit();
private:
	
	
//--------------private--------members-----------------------//
private:
	int m_Score = 0, m_Lives = 5;
	bool m_got_Hit = false;
	std::vector<sf::Sound*>m_S_Buf;

};
