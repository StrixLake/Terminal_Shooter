#pragma once
#include "base_ship.h"

class player_ship : public base_ship
{
public:
	player_ship();
	~player_ship();
	void fire(bullet** bullets_fired, int* num_of_bullets);
	void update_hitpoints();
	void move();
	void hit();

};

