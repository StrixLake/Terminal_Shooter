#include "frame.h"

frame::frame() {
	for (int i = 0; i < YAXIS; ++i) {
		grid[i] = new char[XAXIS];
		for (int j = 0; j < XAXIS; ++j) {
			grid[i][j] = ' ';
		}
	}
	clear();
}


void frame::clear() {
		COORD cursor_pos;
		cursor_pos.X = 0;
		cursor_pos.Y = 0;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor_pos);
}

void frame::reset() {
	for (int i = 0; i < YAXIS; ++i) {
		for (int j = 0; j < XAXIS; ++j) {
			grid[i][j] = ' ';
		}
	}
}

void frame::draw() {
	clear();
	row = "";
	for (int i = 0; i < YAXIS; ++i) {
		for (int j = 0; j < XAXIS; ++j) {
			row += grid[i][j];
		}
		row += '\n';
	}
	std::cout << row;
}

void frame::update() 
{
	reset();
	for (int i = 0; i < num_of_ships; ++i)
	{
		for (int j = 0, ship_x, ship_y, des_pointx = 0, des_pointy = 0; j < ships[i]->hitpoint_numbers; ++j)
		{
			
			ship_x = ships[i]->hitpoints[j][0];
			ship_y = ships[i]->hitpoints[j][1];
			if (ship_y < YAXIS && ship_x < XAXIS) { grid[ship_y][ship_x] = ships[i]->design[des_pointy][des_pointx]; }
			++des_pointx;
			if (des_pointx == ships[i]->design_col[des_pointy]) { des_pointx = 0; ++des_pointy; }
		}
	}
}