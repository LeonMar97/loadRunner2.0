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
