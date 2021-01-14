#include "Enemy.h"
#include "Player.h"

void Enemy:: handleCollision(Game_Object& gameObject) 
{
    if (&gameObject == this) return;
    // double dispatch
    gameObject.handleCollision(*this);
}

void Enemy::handleCollision(Player& gameObject)
{
    // call the player so it can decrease its own live count
    gameObject.handleCollision(*this);
}

void Enemy::handleCollision(Enemy& gameObject)
{
    // ignore
}

void Enemy::handleCollision(Gift& gameObject)
{
    // ignore
}

void Enemy::handleCollision(Money& gameObject)
{
    // ignore
}

void Enemy::effect(void* deltaTime, std::vector<Game_Object*>m_All_Objects[NUM_OF_OBJECTS])
{
    sf::Vector2f next(dirFromKey());
    this->move_Object(next, *(sf::Time*)deltaTime, m_All_Objects);
}
//============================================
sf::Vector2f Enemy::dirFromKey()
{
    srand(time(NULL));
	static const
		std::initializer_list<std::pair<sf::Keyboard::Key, sf::Vector2f>>
		keyToVectorMapping =
	{
		{ sf::Keyboard::Right , { 1, 0 } },
		{ sf::Keyboard::Left , { -1, 0 } },
		{ sf::Keyboard::Up   , { 0, -1 } },
		{ sf::Keyboard::Down , { 0, 1 } }
	};
    
    if (m_enemy_Clock.getElapsedTime().asMilliseconds() > 20)
    {
       
        m_enemy_Clock.restart();
        int random = (rand() % 2) -1 ;

        sf::Vector2f temp (random, 0);
            return { temp.x, 0 };
           
        
    }

	
	return { 0, 0 };
}