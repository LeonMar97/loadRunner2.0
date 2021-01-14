#include <vector>
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "enums_And_Consts.h"
#pragma once

class Sounds_E{
	
	//--------------public--------functions-----------------------//
public:
	static Sounds_E& instance();
	static sf::Sound* get_Sounds() { return m_Sounds[PLAYER_SOUNDS][]; }

	//--------------private--------functions-----------------------//		
	//------------------members-----------------------------------//		
private:
	
	 static std::vector<sf::Sound*>m_Sounds;
};
