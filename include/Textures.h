#include <vector>
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Sounds_E.h"
#pragma once

class Textures {

	//--------------public--------functions-----------------------//
public:
	static Textures& instance();
	//gets requested sound from sound member
	std::vector<sf::Texture*>& get_Textures(int type_E) { return (m_All_textures[type_E]); }

	//--------------private--------functions-----------------------//		
private:

	//------------------members-----------------------------------//		
private:
	Textures();//constractor for static member
	~Textures();
	std::vector<sf::Texture *>m_All_textures[NUM_OF_TEXTURE_OBJECTS];
};
