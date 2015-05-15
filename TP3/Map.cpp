#include "Map.h"

Map::Map()
{
}

Map::~Map()
{
}

Player* Map::getPlayer(int x, int y) const
{
	// todo
	return NULL;
}

bool Map::isEmpty(int x, int y)
{
	//todo Verifier sil y a quelque chose dans la case
	return false;
}
void Map::removePlayer(int x, int y)
{
	//todo
}

void Map::setPlayer(int x, int y, Player *player)
{
	//todo
}

void Map::setBomb(int x, int y, Bomb bomb)
{
	//todo
}

bool Map::isOutOfBound(int x, int y)
{
	return x < 0 || y < 0 || x >= _size || y >= _size;
}

bool Map::hasBomb(int x, int y)
{
	//todo
	return false;
}

bool Map::hasPlayer(int x, int y)
{
	//todo
	return false;
}