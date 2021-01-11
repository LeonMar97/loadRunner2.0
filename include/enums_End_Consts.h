enum element {
	player = '@',
	money = '*',
	wall = '#',
	smart = '%',
	stupid = '&',
	med = '$',
	gift = '!',
	pole = '-',
	ladder = 'H',
	space = 'r'
	};
enum location_In_Vector {
	walls = 0,
	ladders=1,
	poles=2,
	disappear=3,
	enemys = 4,
	players = 5
};
const unsigned int NUM_OF_OBJECTS = 6;
enum Direction_left_right {
	left = 0,
	right=1
};
const sf::Vector2f start_Of_Map(350, 100);//start location