#include "frame.h"

frame::frame() {
	for (int i = 0; i < 20; ++i) {
		grid[i] = new char[200];
		for (int j = 0; j < 200; ++j) {
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
void frame::draw() {
	clear();
	row = "";
	for (int i = 0; i < 20; ++i) {
		for (int j = 0; j < 200; ++j) {
			row += grid[i][j];
		}
		std::cout << row << "\n";
		row = "";
	}
}

void frame::update() 
{
	for (int i = 0, ship_point_x, ship_point_y; i < num_of_ships; ++i) 
	{
		for (int j = 0; j < ships[i]->hitpoint_numbers; ++j) 
		{
			ship_point_x = ships[i]->hitpoints[j][0];
			ship_point_y = ships[i]->hitpoints[j][1];
			for (int desig_rows = 0; desig_rows < ships[i]->design_rows; ++desig_rows)
			{
				for (int y = 0; y < ships[i]->design_col[desig_rows]; ++y)
				{
					grid[ship_point_y][ship_point_x] = static_cast<char> (ships[i]->design[desig_rows][y]);
				}
			}
		}
	}
}