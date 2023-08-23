#pragma once
#include "windows.h"
#include "winuser.h"
#include <iostream>
#include <string>

class frame
{	
public:
	frame();
	void update();
	void draw();
	char* grid[20];
private:
	void clear();
	std::string row;
};

