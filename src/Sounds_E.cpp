#include "Sounds_E.h"

 Sounds_E& Sounds_E:: instance() {
	 static Sounds_E  all_S;
	return all_S;
}
 //set the sound once for the game,just once!!!
Sounds_E::Sounds_E() {
	std::vector<std::string>names[] = { {"grunt4.wav",
										"money.wav",
										"sound_062.wav"},
										{
										"GENERIC_THANKS_02.wav",
										"GAME_WIN_SELF_01.wav",
										"ARRESTED_DRUNK_03.wav",
										"BASEJUMP_ABOUT_TO_JUMP_03.wav"},
										{
											"leave.wav",
											"start.wav"
										} 
	};
	std::vector<std::string>music_name = { "theme song.ogg" };

	int j;
	sf::SoundBuffer* sd;//sound
	sf::Sound* sound;
	std::vector<sf::SoundBuffer*>sd_buf;
	for (int i = 0; i < SOUND_TYPES; i++) {
		for (j = 0; j < names[i].size(); j++) {
			sd = new sf::SoundBuffer;
			sound = new sf::Sound;

			if (!sd->loadFromFile(names[i][j])) {
				std::cout << "couldnt load sound" << names[i][j] << "\n";
			}
			sound->setBuffer(*sd);
			sound->setVolume(15);
			m_Sounds[i].push_back(sound);

		}
	}
	for (j = 0; j < music_name.size(); j++) {
		sf::Music* cur = new sf::Music;
		if(!cur->openFromFile(music_name[j]))
			std::cout << "couldnt load music" << music_name[j] << "\n";
		cur->setVolume(10);
		m_Music.push_back(cur);
	}

}
 
Sounds_E::~Sounds_E()
{
	for (int i = 0; i < m_Sounds->size(); i++)
	{
		m_Sounds[i].clear();
	}
	m_Sounds->clear();
}


	


	 