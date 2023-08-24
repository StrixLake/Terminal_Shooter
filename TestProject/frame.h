#pragma once
#include "windows.h"
#include "winuser.h"
#include <iostream>
#include <string>
#include "base_ship.h"

class frame
{	
public:
	frame();
	void update();
	void draw();
	char* grid[20];
	base_ship** ships = new base_ship*[10];
	int num_of_ships;

private:
	void clear();
	std::string row;
};

