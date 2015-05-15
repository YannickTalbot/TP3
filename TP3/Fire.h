#pragma once

#include "Position.h"
#include "Map.h"

class Fire
{
private:
	Position _position;
	Map* _map;
	int _timeLeft;

public:
	Fire(Position position, Map* map);
	~Fire();

	void tick();

	//retourne vrai si le feu a fini de bruler
	bool isDone();
};
