#include <iostream>
#include "frame.h"
#include "player_ship.h"


int main()
{
	frame Frame;
	player_ship ship;
	Frame.num_of_ships = 1;
	Frame.ships[0] = &ship;
	while (!GetAsyncKeyState(VK_ESCAPE)) {
		Frame.draw();
		Frame.update();
		Sleep(25);
	}
	return 0;
}

