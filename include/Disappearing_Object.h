#include "Game_Object.h"
#include "Player.h"
#include "Enemy.h"
#pragma once
class Disappearing_Object :public Game_Object {

public://functions
    using Game_Object::Game_Object;
	void handleCollision(Game_Object& gameObject)override {};
	void handleCollision(Enemy& gameObject)override {};
	void handleCollision(Money& gameObject)override {};
	void handleCollision(Player& gameObject)override {};
	void handleCollision(Gift& gameObject)override {};
	bool get_deleted() {return m_deleted;}
private:

protected:
	bool m_deleted = false;


};

