#include "Bomb.h"
#include "Fire.h"
#include <SFML\Graphics.hpp>

//Constructeurs
Bomb::Bomb(sf::Sprite *image, Player* player, int power, Map* map)
{
	_player = player;
	_image = image;
	_fuse = 3;
	_power = power;
	_map = map;
}

Bomb::~Bomb()
{
}

//Getter
sf::Sprite* Bomb::getImage() const
{
	return _image;
}

//le temps de la bombe avant qu'elle explose
void Bomb::tick()
{
	if (_fuse == 0)
	{
		explode();
	}
	else
	{
		_fuse--;
	}
}

//indicateur si la bombe a exploser
bool Bomb::hasExploded()
{
	return _fuse == 0;
}


void Bomb::drawFireLine(function<int&(Position&)> dimension, int direction)
{
	for (int i = 0; i < _power; i++)
	{
		Position p = _position;
		dimension(p) += direction * (i + 1);

		if (_map->hasUnbreakableWall(p._x, p._y))
		{
			break;
		}

		if (_map->hasBreakableWall(p._x, p._y))
		{
			_map->removeBreakableWall(p._x, p._y);
			break;
		}

		//_map->setFire(p._x, p._y, Fire(p, _map));
	}
}

int& dimensionX(Position& p)
{
	return p._x;
}

int& dimensionY(Position& p)
{
	return p._y;
}

void Bomb::explode()
{
	drawFireLine(dimensionX, 1);
	drawFireLine(dimensionX, -1);
	drawFireLine(dimensionY, 1);
	drawFireLine(dimensionY, -1);

	_player->notifyBombExploded();
}

Position Bomb::getPosition() const
{
	return _position;
}

void Bomb::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
}