#include "Fire.h"

Fire::Fire(Position position, Map* map)
{
	_timeLeft = 5;
	_position = position;
	_map = map;
}