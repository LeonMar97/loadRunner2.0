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