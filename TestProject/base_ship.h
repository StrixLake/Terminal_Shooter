#pragma once
#include <string>
using std::string;
#ifndef YAXIS
#define YAXIS 50
#endif
#ifndef XAXIS
#define XAXIS 250
#endif

class base_ship
{
public:
	int health;
	int x_coordinates;
	int y_coordinates;
	string* design;
	int design_rows;
	int* design_col = new int[design_rows];
	int** hitpoints;
	int hitpoint_numbers;
	virtual void move(char direction){}
	virtual int hit() { return 1; }
	virtual void update_hitpoints() {}
};

