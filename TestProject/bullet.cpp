#include "bullet.h"

bullet::bullet(char fire_direction, int ship_Xcoordinate, int ship_Ycoordinate)
{
	position = new int[2];
	position[0] = ship_Xcoordinate; position[1] = ship_Ycoordinate;
	direction = fire_direction;
}

void bullet::move()
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
}

bullet::~bullet()
{
	delete position;
	position = nullptr;
}