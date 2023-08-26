#include <iostream>
#include "frame.h"
#include "player_ship.h"
#include "enemy_ship.h"


int main()
{
	frame Frame;
	Frame.ships[0] = new player_ship();
	Frame.ships[1] = new enemy_ship();
	Frame.num_of_ships = 2;
	while (!GetAsyncKeyState(VK_ESCAPE)) {
		Frame.draw();
		Frame.update();
		Sleep(25);
	}
	return 0;
}

