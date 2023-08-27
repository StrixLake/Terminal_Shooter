#include <iostream>
#include "frame.h"
#include "player_ship.h"
#include "enemy_ship.h"


int main()
{
	std::cout << "press enter to start" << std::endl;
	std::cin.get();
	int total_ships_spawned = 3;
	frame Frame;
	Frame.ships[0] = new player_ship();
	Frame.ships[1] = new enemy_ship(25);
	Frame.ships[2] = new enemy_ship(199);
	Frame.num_of_ships = 3;
	while (!GetAsyncKeyState(VK_ESCAPE) && Frame.ships[0]->isPlayer) {
		Frame.draw();
		Frame.update();
		if (Frame.num_of_ships < 3)
		{
			if (total_ships_spawned % 2)
				Frame.ships[Frame.num_of_ships] = new enemy_ship(25);
			else
				Frame.ships[Frame.num_of_ships] = new enemy_ship(199);
			++Frame.num_of_ships;
			++total_ships_spawned;
		}
		Sleep(25);
	}
//	Frame.reset();
	Frame.draw();
//	Frame.clear();
	std::cout << "Game Over" << std::endl;
	std::cout << "Score: " << Frame.score << std::endl;
	return 0;
}

