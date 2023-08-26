#include "enemy_ship.h"

enemy_ship::enemy_ship()
{
	health = 100;
	x_coordinates = 25;
	y_coordinates = 10;

	design = new string[4];
	design_rows = 4;
	design_col = new int[design_rows];
	design[0] = string("_______________"); //15
	design[1] = string("/\\____     ____/\\"); //17
	design[2] = string("/ /\\___\\   /___/\\ \\"); //19
	design[3] = string("\\/  \\___   ___/  \\/"); //19
	design_col[0] = 15; design_col[1] = 17; design_col[2] = 19; design_col[3] = 19;

	hitpoints = new int* [70];
	hitpoint_numbers = 70;
	for (int i = 0; i < 70; ++i) {
		hitpoints[i] = new int[2];
	}
	update_hitpoints();
}

enemy_ship::~enemy_ship()
{
	for (int i = 0; i < hitpoint_numbers; ++i) {
		delete[] hitpoints[i];
	}
	delete[] hitpoints;
	hitpoints = nullptr;
	delete[] design;
	design = nullptr;
	delete[] design_col;
	design_col = nullptr;
}

void enemy_ship::update_hitpoints()
{
	for (int i = 0, temp = 2 ; i < 15; ++i)
	{
		hitpoints[i][0] = x_coordinates + temp; hitpoints[i][1] = y_coordinates - 3;
		++temp;
	}
	for (int i = 15, temp = 1; i < 32; ++i)
	{
		hitpoints[i][0] = x_coordinates + temp; hitpoints[i][1] = y_coordinates - 2;
		++temp;
	}
	for (int i = 32, temp = 0; i < 51; ++i)
	{
		hitpoints[i][0] = x_coordinates + temp; hitpoints[i][1] = y_coordinates - 1;
		++temp;
	}
	for (int i = 51, temp = 0; i < 70; ++i)
	{
		hitpoints[i][0] = x_coordinates + temp; hitpoints[i][1] = y_coordinates;
		++temp;
	}
}

void enemy_ship::move()
{

}

void enemy_ship::fire(bullet** bullets_fired, int* num_of_bullets)
{
	
}

void enemy_ship::hit()
{
	health -= 10;
}
