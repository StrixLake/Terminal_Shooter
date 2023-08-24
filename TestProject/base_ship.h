#pragma once
#include <string>
using std::string;

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
	virtual void move(char){}
	virtual int hit() { return 1; }
	virtual void update_hitpoints() {}
};

