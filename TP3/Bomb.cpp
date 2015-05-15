#include "Bomb.h"
#include <SFML\Graphics.hpp>

Bomb::Bomb(sf::Image *image, Player* player, int power)
{
	_player = player;
	_image = image;
	_fuse = 3;
	_power = power;
}

Bomb::~Bomb()
{
}

sf::Image* Bomb::getImage() const
{
	return _image;
}

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

bool Bomb::hasExploded()
{
	return _fuse == 0;
}

void Bomb::explode()
{
	for (int i = 0; i < _power; i++)
	{

	}
}
