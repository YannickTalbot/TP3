#include "Player.h"

Player::Player() {}

Player::Player(Position initialPosition, Map *map, 
	sf::Sprite upImage, sf::Sprite downImage,
	sf::Sprite leftImage, sf::Sprite rightImage)
{
	_map = map;
	_initialPosition = initialPosition;
	_position = initialPosition;
	_lives = 3;
	_bombsInPlay = 0; // bombe dans le world
	resetStats();

	_currentDirection = DOWN;
	_directionImages[UP] = upImage;
	_directionImages[DOWN] = downImage;
	_directionImages[LEFT] = leftImage;
	_directionImages[RIGHT] = rightImage;
}

//remet les stats de depart du players
void Player::resetStats()
{
	_speed = 1;
	_power = 1;
	_maxBombsInPlay = 1;
}

Player::~Player()
{
}

//fonction quand un player se fait tuer
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

//Fonction pour placer une bombe dans la map
void Player::placeBomb()
{
	if (_bombsInPlay < _maxBombsInPlay && !_map->hasBomb(_position._x,_position._y))
	{
		_bombsInPlay++;
		Bomb bomb(&_bombImage, this, _power, _map);
		//setBomb utilise les coordonnées de getPosition de la bombe
		_map->setBomb(/*_position._x, _position._y*/ bomb);

	}
}

//fonction pour bouger en haut
void Player::moveUp()
{
	moveTo(_position._x, _position._y - 1);
	_currentDirection = UP;
	
}

//fonction pour bouger en bas
void Player::moveDown()
{
	moveTo(_position._x, _position._y + 1);
	_currentDirection = DOWN;
}

//fonction pour bouger a gauche
void Player::moveLeft()
{
	moveTo(_position._x -1, _position._y);
	_currentDirection = LEFT;
}

//fonction pour bouger a droite
void Player::moveRight()
{
	moveTo(_position._x +1, _position._y);
	_currentDirection = RIGHT;
}

//fonction primaire pour bouger dans la map
void Player::moveTo(const int x, const int y)
{
	if (!_map->isOutOfBound(x, y) && _map->isEmpty(x, y))
	{
		_map->removePlayer(_position._x, _position._y);
		_position._x = x;
		_position._y = y;
		_map->setPlayer(_position._x, _position._y, this);
	}
}

//notifie quand une bombe explose et decremente les bombs en jeu
void Player::notifyBombExploded()
{
	_bombsInPlay--;
}

//dessine le player
void Player::draw(sf::RenderTarget& target, sf::RenderStates states)
{
	_directionImages[_currentDirection].setPosition((float)_position._x, (float)_position._y);
	target.draw(_directionImages[_currentDirection]);
}
//sf::Sprite& Player::getImage()
//{
//	return _directionImages[_currentDirection];
//}
//blablablala
