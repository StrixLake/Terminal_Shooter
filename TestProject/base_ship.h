#pragma once
#include <string>
#include "windows.h"
#include "winuser.h"
#include "bullet.h"
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
	int* design_col;
	int** hitpoints;
	int hitpoint_numbers;
	
	virtual void move(){}
	virtual void hit() {}
	virtual void update_hitpoints() {}
	virtual void fire(bullet** bullets_fired, int* num_of_bullets) {}
};

