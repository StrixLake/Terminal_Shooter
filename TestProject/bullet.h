#pragma once
#ifndef YAXIS
#define YAXIS 50
#endif
#ifndef XAXIS
#define XAXIS 250
#endif


class bullet
{
public:
	char direction;
	bullet(char fire_direction, int ship_Xcoordinate, int ship_Ycoordinate);
	int* position;
	void move();
	~bullet();
};

