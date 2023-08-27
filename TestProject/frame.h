#pragma once
#include "windows.h"
#include "winuser.h"
#include <iostream>
#include <string>
#include "base_ship.h"
#include "bullet.h"
#define XAXIS 250
#define YAXIS 50


class frame
{	
public:
	frame();
	void update();
	void draw();
	void reset();
	void clear();
	
	int score = 0;
	char* grid[YAXIS];
	base_ship** ships = new base_ship*[10];
	int num_of_ships = 0;

private:
	std::string rowToPrint;
	int num_of_bullets = 0;
	bullet** bullets_fired = new bullet* [500];

	void render_ship();
	void render_bullets();
	void move_objects();
	void move_ships();
	void move_bullets();
	void check_Hits();
	void check_health();
	bool arrMatch(int* bulletPosition, int** shipHitpoints, int numOFHitpoints);
	void delete_element(bullet** bullets_fired, int* num_of_bullets, int itemToDelete);
	void delete_element(base_ship** ships, int* num_of_ships, int itemToDelete);
};



