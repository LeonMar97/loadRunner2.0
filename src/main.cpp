#include "Board.h"
#include "Controller.h"
int main() {
	srand(time(NULL));
	Controller game;
	game.start_Game();

	return EXIT_SUCCESS;
}