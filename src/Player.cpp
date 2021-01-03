#include "Player.h"


void Player::setscore(int score)
{
	m_Score = score;
}
int Player::getscore()const {

}
int Player::getlives()const
{
	return m_Lives;
}
void Player::setlives(int lives)
{
	m_Lives = lives;
}
void Player::move(sf::Keyboard::Key key)
{
	switch (key)
	{
	case sf::Keyboard::Key::Up:

		break;

	case sf::Keyboard::Key::Down:

		break;
	case sf::Keyboard::Key::Left:

		break;
	case sf::Keyboard::Key::Right:

		break;

	}
}