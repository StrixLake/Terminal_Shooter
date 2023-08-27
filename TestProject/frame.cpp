#include "frame.h"

frame::frame() 
{
	for (int i = 0; i < YAXIS; ++i) {
		grid[i] = new char[XAXIS];
		for (int j = 0; j < XAXIS; ++j) {
			grid[i][j] = ' ';
		}
	}
	clear();
}


void frame::clear() {
		COORD cursor_pos;
		cursor_pos.X = 0;
		cursor_pos.Y = 0;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor_pos);
}

void frame::reset() {
	for (int i = 0; i < YAXIS; ++i) {
		for (int j = 0; j < XAXIS; ++j) {
			grid[i][j] = ' ';
		}
	}
}

void frame::draw() {
	clear();
	if (ships[0]->isPlayer)
	{
		std::cout << "Health: " << ships[0]->health << "             " << std::endl;
		std::cout << "Score: " << score << "    " << std::endl;
	}
	rowToPrint = "";
	for (int i = 0; i < YAXIS; ++i) {
		for (int j = 0; j < XAXIS; ++j) {
			rowToPrint += grid[i][j];
		}
		rowToPrint += '\n';
	}
	std::cout << rowToPrint;
}

void frame::update() 
{
	move_objects();
	reset();
	render_ship();
	render_bullets();
}

void frame::render_ship()
{
	for (int i = 0; i < num_of_ships; ++i)
	{
		for (int j = 0, ship_x, ship_y, des_pointx = 0, des_pointy = 0; j < ships[i]->hitpoint_numbers; ++j)
		{

			ship_x = ships[i]->hitpoints[j][0];
			ship_y = ships[i]->hitpoints[j][1];
			if (ship_y < YAXIS && ship_x < XAXIS) { grid[ship_y][ship_x] = ships[i]->design[des_pointy][des_pointx]; }
			++des_pointx;
			if (des_pointx == ships[i]->design_col[des_pointy]) { des_pointx = 0; ++des_pointy; }
		}
	}
}

void frame::render_bullets()
{
	for (int i = 0; i < num_of_bullets; ++i)
	{
		if (bullets_fired[i] -> direction == 'a') { grid[bullets_fired[i]->position[1]][bullets_fired[i]->position[0]] = '/'; }
		else if (bullets_fired[i]->direction == 'd') { grid[bullets_fired[i]->position[1]][bullets_fired[i]->position[0]] = '\\'; }
		else { grid[bullets_fired[i]->position[1]][bullets_fired[i]->position[0]] = '|'; }
	}
}

void frame::move_objects()
{
	move_ships();
	move_bullets();
	check_Hits();
	check_health();
}

void frame::move_ships()
{
	for (int i = 0; i < num_of_ships; ++i)
	{
		ships[i]->move();
		ships[i]->fire(bullets_fired, &num_of_bullets);
	}
}

void frame::move_bullets()
{
	for (int i = 0; i < num_of_bullets; ++i)
	{
		bullets_fired[i]->move();
	}
}

void frame::check_Hits()
{
	for (int y = 0; y < num_of_ships; ++y)
	{
		for (int x = 0; x < num_of_bullets; ++x)
		{
			if (bullets_fired[x]->position[0] < 0 || bullets_fired[x]->position[1] < 0 || bullets_fired[x]->position[0] >= XAXIS || bullets_fired[x]->position[1] >= YAXIS)
			{
				delete_element(bullets_fired, &num_of_bullets, x);
				--x;
			}
			else if (arrMatch(bullets_fired[x]->position, ships[y]->hitpoints, ships[y]->hitpoint_numbers))
			{
				delete_element(bullets_fired, &num_of_bullets, x);
				--x;
				ships[y]->hit();

			}
		}
	}
}

void frame::check_health()
{
	for (int i = 0; i < num_of_ships; ++i)
	{
		if (ships[i]->health < 0)
		{
			delete_element(ships, &num_of_ships, i);
			--i;
		}
	}
}

void frame::delete_element(base_ship** ships, int* num_of_ships, int itemToDelete)
{
	delete ships[itemToDelete];
	ships[itemToDelete] = nullptr;
	for (int i = itemToDelete; i < *num_of_ships - 1; ++i)
	{
		ships[i] = ships[i + 1];
	}
	-- * num_of_ships;
	++score;
}

void frame::delete_element(bullet** bullets_fired, int* num_of_bullets, int itemToDelete)
{
	delete bullets_fired[itemToDelete];
	bullets_fired[itemToDelete] = nullptr;
	for (int i = itemToDelete; i < *num_of_bullets - 1; ++i)
	{
		bullets_fired[i] = bullets_fired[i + 1];
	}
	-- * num_of_bullets;
}

bool frame::arrMatch(int* bulletPosition, int** shipHitpoints, int numOFHitpoints)
{
	if (bulletPosition[0] < 0 || bulletPosition[0] > XAXIS || bulletPosition[1] > YAXIS || bulletPosition[1] < 0)
	{
		return true;
	}
	for (int i = 0; i < numOFHitpoints; ++i)
	{
		if (bulletPosition[0] == shipHitpoints[i][0] && bulletPosition[1] == shipHitpoints[i][1])
		{
			return true;
		}
	}
	return false;
}
