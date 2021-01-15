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
	//gets requested sound from sound member
	 sf::Sound &get_Sounds(int type_E,int sound) { return*(m_Sounds[type_E][sound]);}

	//--------------private--------functions-----------------------//		
private:

	//------------------members-----------------------------------//		
private:
		Sounds_E();//constractor for static member
		~Sounds_E();
		 std::vector<sf::Sound*>m_Sounds[SOUND_TYPES];
};
