#pragma once

struct Position{
	int _x;
	int _y;
	int _size;

	Position(int x, int y, int size)
	{
		_x = x;
		_y = y;
		_size = size;
	}
	Position(){}
};