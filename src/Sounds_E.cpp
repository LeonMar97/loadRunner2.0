#include "Sounds_E.h"
Sounds_E::Sounds_E(){
std::vector<std::string>names[] = {{"grunt4.wav",
									"money.wav",
									"sound_062.wav"},{
									"GENERIC_THANKS_02.wav",
									"GAME_WIN_SELF_01.wav",
									"ARRESTED_DRUNK_03.wav",
									"BASEJUMP_ABOUT_TO_JUMP_03.wav"}};

	int j;
	sf::SoundBuffer* sd;//sound
	sf::Sound* sound ;
	
	for (int i = 0; i < 2; i++) {
		for (j = 0; j < names[j].size(); j++) {
			sd = new sf::SoundBuffer;
			sound = new sf::Sound;
			if (!sd->loadFromFile(names[i][j])) {
				std::cout << "couldnt load sound"<<names[i][j]<<"\n";
			}
		
		}
	}



	 