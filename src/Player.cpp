#include "Player.h"

Player::Player(sf::Vector2f player_first_loc) {
	m_Lives = 3;
	m_Score = 0;

	m_Pic = new sf::Texture;
	m_Pic->loadFromFile("player.png");
	m_Player.setTexture(*m_Pic);
	m_Player.setPosition(player_first_loc);
	m_Player.setOrigin(player_first_loc);
}
//========================================