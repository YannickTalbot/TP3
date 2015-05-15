#include "Player.h"


Player::Player(Position initialPosition, Map *map)
{
	_map = map;
	_initialPosition = initialPosition;
	_position = initialPosition;
	_lives = 3;
	_bombsInPlay = 0; // bombe dans le world
	//todo initialise : bomb image, direction image,
	resetStats();
}

void Player::resetStats()
{
	_speed = 1;
	_power = 1;
	_maxBombsInPlay = 1;
}

Player::~Player()
{
}

void Player::kill()
{
	if (_lives < 1)
	{
		_map->removePlayer(_position._x, _position._y);
	}
	else
	{
		_lives -= 1;
		moveTo(_initialPosition._x, _initialPosition._y);
		resetStats();
	}
	

}

void Player::placeBomb()
{
	if (_bombsInPlay < _maxBombsInPlay && !_map->hasBomb(_position._x,_position._y))
	{
		_bombsInPlay++;
		Bomb bomb(&_bombImage, this, _power, _map);
		_map->setBomb(_position._x, _position._y, bomb);

	}
}

void Player::moveUp()
{
	moveTo(_position._x, _position._y - 1);
}

void Player::moveDown()
{
	moveTo(_position._x, _position._y + 1);
}

void Player::moveLeft()
{
	moveTo(_position._x -1, _position._y);
}

void Player::moveRight()
{
	moveTo(_position._x +1, _position._y);
}

void Player::moveTo(int x, int y)
{
	if (!_map->isOutOfBound(x, y) && _map->isEmpty(x, y))
	{
		_map->removePlayer(_position._x, _position._y);
		_position._x = x;
		_position._y = y;
		_map->setPlayer(_position._x, _position._y, this);
	}
}