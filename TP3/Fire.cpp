#include "Fire.h"

Fire::Fire(Position position, Map* map)
{
	_timeLeft = 5;
	_position = position;
	_map = map;
}

Fire::~Fire()
{

}

//Le temps du feu sur la map
void Fire::tick()
{
	if (!isDone())
	{
		_timeLeft--;
		if (_map->hasPlayer(_position._x, _position._y))
		{
			_map->getPlayer(_position._x, _position._y)->kill();
		}
	}
}

//demande si le feu a fini de tick
bool Fire::isDone()
{
	return _timeLeft == 0;
}

