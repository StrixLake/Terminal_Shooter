#pragma once
#ifndef YAXIS
#define YAXIS 50
#endif
#ifndef XAXIS
#define XAXIS 250
#endif


class bullet
{
	char direction;
public:
	bullet(char fire_direction, int ship_Xcoordinate, int ship_Ycoordinate);
	int* position;
	int move();
	~bullet();
};

