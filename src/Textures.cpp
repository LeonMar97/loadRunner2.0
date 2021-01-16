#include "Textures.h" 
#pragma once
Textures& Textures::instance() {
	static Textures  all_S;
	return all_S;
}

 Textures::Textures() {
	std::vector<std::string>names[] = {
						  {"wall.png"},
						  {"ladder.png"},
						  {"pole.png"},
						  {"money.png"},
						  {"gift.png"},
						  {"smart_Enemy.png"},
						  {"med_Enemy.png"},
						  {"stupid_Enemy.png"},
						  {"cjsk.png","cj2.png"},
						  {"background2.png"},
						  {"scoreBoard.png"}
											};

	int i, j;

	sf::Texture *pic;
	for (i = walls; i < NUM_OF_TEXTURE_OBJECTS; i++) {
		for (j = 0; j < names[i].size(); j++) {
			pic = new sf::Texture;
			pic->loadFromFile(names[i][j]);
			m_All_textures[i].push_back(pic);
		}

	}



	


}
 Textures::~Textures()
 {
	 for (int i = 0; i < m_All_textures->size(); i++)
	 {
		m_All_textures[i].clear();
	 }
	 m_All_textures->clear();
 }