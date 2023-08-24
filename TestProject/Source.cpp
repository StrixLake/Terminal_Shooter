#include <iostream>
#include "frame.h"
#include "player_ship.h"


int main()
{
	frame Frame;
	player_ship ship;
	//std::cout << ship.design[2];
	//std::cin.get();
	Frame.num_of_ships = 1;
	Frame.ships[0] = &ship;
	//std::cin.get();
	Frame.draw();
	std::cin.get();
	Frame.update();
	std::cin.get();
	Frame.draw();
	//std::cin.get();
	return 0;
}

