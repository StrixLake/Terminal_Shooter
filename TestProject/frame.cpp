#include "frame.h"



frame::frame() {
	for (int i = 0; i < 20; ++i) {
		grid[i] = new char[200];
		for (int j = 0; j < 200; ++j) {
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
void frame::draw() {
	clear();
	row = "";
	for (int i = 0; i < 20; ++i) {
		for (int j = 0; j < 200; ++j) {
			row += grid[i][j];
		}
		std::cout << row << "\n";
		row = "";
	}
}