#include "Board.h"
#include "Controller.h"
int main() {
	Board x;
	x.print_Map();
	Controller y;
	y.start_Game();

	return EXIT_SUCCESS;
}