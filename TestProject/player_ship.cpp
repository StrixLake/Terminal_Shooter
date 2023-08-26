#include "player_ship.h"

player_ship::player_ship() {
	health = 100;
	x_coordinates = 150;
	y_coordinates = 10;
	
	design = new string [4];
	design_rows = 4;
	design[0] = string("/\\");
	design[1] = string("___/  \\___");
	design[2] = string("/__________\\");
	design[3] = string("/____________\\");
	design_col[0] = 2; design_col[1] = 10; design_col[2] = 12; design_col[3] = 14;

	hitpoints = new int* [38];
	hitpoint_numbers = 38;
	for (int i = 0; i < 38; ++i) {
		hitpoints[i] = new int[2];
	}
	update_hitpoints();

}

void player_ship::update_hitpoints() {
	hitpoints[0][0] = x_coordinates; hitpoints[0][1] = y_coordinates; hitpoints[1][0] = x_coordinates +1; hitpoints[1][1] = y_coordinates;
	for (int i = 2, temp = -4; i < 12; ++i) {
		hitpoints[i][0] = x_coordinates + temp;
		hitpoints[i][1] = y_coordinates + 1;
		++temp;
	}
	for (int i = 12, temp = -5; i < 24; ++i) {
		hitpoints[i][0] = x_coordinates + temp;
		hitpoints[i][1] = y_coordinates + 2;
		++temp;
	}
	for (int i = 24, temp = -6; i < 38; ++i) {
		hitpoints[i][0] = x_coordinates + temp;
		hitpoints[i][1] = y_coordinates + 3;
		++temp;
	}
}


void player_ship::move()
{
	if (GetAsyncKeyState(VK_UP) < 0 && y_coordinates > 0) { --y_coordinates; }
	if (GetAsyncKeyState(VK_DOWN) < 0 && y_coordinates < YAXIS) { ++y_coordinates; }
	if (GetAsyncKeyState(VK_RIGHT) < 0 && x_coordinates < XAXIS) { x_coordinates += 2; }
	if (GetAsyncKeyState(VK_LEFT) < 0 && x_coordinates > 0) { x_coordinates -= 2; }
	update_hitpoints();
}

void player_ship::fire(bullet** bullets_fired, int* num_of_bullets)
{
	if (GetAsyncKeyState(VK_SPACE) < 0 && *num_of_bullets < 99) 
	{
		bullet* fired = new bullet('w', x_coordinates, y_coordinates);
		bullets_fired[*num_of_bullets] = fired;
		*num_of_bullets += 1;
	}
}
