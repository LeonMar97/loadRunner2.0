#include "Player.h"


void Player::setscore(int score)
{
	m_Score = score;
}
int Player::getscore()const {
	return m_Score;
}
int Player::getlives()const
{
	return m_Lives;
}
void Player::setlives(int lives)
{
	m_Lives = lives;
}
//===================================================
void Player::effect(void* deltaTime, std::vector<Game_Object*>m_All_Objects[NUM_OF_OBJECTS])
{
	sf::Vector2f next(dirFromKey());
	this->move_Object(next,*(sf::Time*) deltaTime, m_All_Objects);
}


//===================================================
sf::Vector2f Player::dirFromKey()
{
		
		static const
			std::initializer_list<std::pair<sf::Keyboard::Key, sf::Vector2f>>
			keyToVectorMapping =
		{
			{ sf::Keyboard::Right , { 1, 0 } },
			{ sf::Keyboard::Left , { -1, 0 } },
			{ sf::Keyboard::Up   , { 0, -1 } },
			{ sf::Keyboard::Down , { 0, 1 } },
			{ sf::Keyboard::X , { 1, 1 } },
			{sf::Keyboard::Z, { -1,1  }
}
		};

		for (const auto& pair : keyToVectorMapping)
		{
			
			if (sf::Keyboard::isKeyPressed(pair.first))
			{
				
				return pair.second;

	
			}
			
		}

		return { 0, 0 };
	}

//==========================================================
	void Player::handleCollision(Game_Object& gameObject)
	{
		if (&gameObject == this) return;
		//double dispatch
		gameObject.handleCollision(*this);
	}




//===========================================================
void Player::handleCollision(Money& money) 
{
	m_Score+=2;
	Sounds_E::instance().get_Sounds(PLAYER_SOUNDS, player_money).play();
	
}
//==============================================================
void Player::handleCollision(Wall& gameObject)
{
	Sounds_E::instance().get_Sounds(PLAYER_SOUNDS, player_hole).play();
	m_Elemnt_Of_Game.move(0, -m_Elemnt_Of_Game.getGlobalBounds().height / 3);
}
//==============================================================

void Player::handleCollision(Enemy& enemy) 
{
	Sounds_E::instance().get_Sounds(PLAYER_SOUNDS, player_hit).play();
	m_Lives--;
	m_got_Hit = true;
}
//============================================================
void Player::set_hit(bool hit)
{
	m_got_Hit = hit;
}
//============================================================
bool Player::get_hit()
{
	return m_got_Hit;
}
//============================================================
