#include "bullet.h"

bullet::bullet(char fire_direction, int ship_Xcoordinate, int ship_Ycoordinate)
{
	position = new int[2];
	position[0] = ship_Xcoordinate; position[1] = ship_Ycoordinate;
	direction = fire_direction;
}

int bullet::move()
{
	if (position[0] < XAXIS && position[1] < YAXIS && position[0] > 0 && position[1] > 0)
	{
		switch (direction)
		{
		case('w'):
			--position[1];
			break;
		case('a'):
			--position[0];
			++position[1];
			break;
		case('s'):
			++position[1];
			break;
		case('d'):
			++position[0];
			++position[1];
			break;
		}
		return 1;
	}
	else
	{
		return 0;
	}
}

bullet::~bullet()
{
	delete position;
	position = nullptr;
}