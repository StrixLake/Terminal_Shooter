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
		if (GetAsyncKeyState(VK_UP) < 0) { ship.move('w'); }
		if (GetAsyncKeyState(VK_DOWN) < 0) { ship.move('s'); }
		if (GetAsyncKeyState(VK_RIGHT) < 0) { ship.move('d'); }
		if (GetAsyncKeyState(VK_LEFT) < 0) { ship.move('a'); }
		Frame.update();
		Frame.draw();
		Sleep(25);
	}
	return 0;
}

