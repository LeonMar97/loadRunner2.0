enum element {
	player = '@',
	money = '*',
	wall = '#',
	smart = '%',
	stupid = '&',
	med = '$',
	gift = 'G',
	pole = '-',
	ladder = 'H',
	space = 'r'
	};
enum location_In_Vector {
	walls = 0,
	ladders=1,
	poles=2,
	moneys=3,
	gifts = 4,
	enemys = 5,
	players = 6
};
enum Direction_left_right {
	left = 0,
	right=1
};
enum scores {
	sc = 0,
	lvl = 1,
	lf = 2
};
enum Gifts_Kinds {
	gift_1 = 1,
	gift_2 = 2,
	gift_3 = 3,
	gift_4 = 4

};
enum digging {
	left_dig=1,
	right_dig=2,
	undig=0
};
enum sounds {
	player_hit = 0,
	player_money = 1,
	player_hole = 2,
	gift_life = 0,
	gift_score = 1,
	gift_enemy=2,
	gift_time =3
};
const int SOUND_TYPES = 2;
const int PLAYER_SOUNDS = 0;
const int GIFT_SOUNDS = 1;
const int EXTRA_TIME = 30;
const sf::Vector2f start_Of_Map(350, 150);//start location
const unsigned int NUM_OF_OBJECTS = 7;
