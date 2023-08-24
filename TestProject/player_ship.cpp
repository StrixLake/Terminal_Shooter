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
//	design[0] = "/\\";
//	design[1] = "___/  \\___";
//	design[2] = "/__________\\";
//	design[4] = "/____________\\";
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
