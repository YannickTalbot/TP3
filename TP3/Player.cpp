#include "Player.h"

Player::Player() {}

Player::Player(Position initialPosition, Map *map, sf::Texture &texture, ScaleInfo *scale)
{
	_map = map;
	_currentDirection = DOWN;
	_initialPosition = initialPosition;
	_position = initialPosition;
	_lives = 3;
	_bombsInPlay = 0; // bombe dans le world
	resetStats();
	_scale = scale;

	for (int i = 0; i < 12; i++)
	{
		_directionImages[i / 4][i % 3].setTexture(texture);
	}

	//Les sprites font 16X32
	for (int i = 0; i < 3; i++)
	{
		//Positionne les rectangles dans les sprites
		_directionImages[UP][i].setTextureRect(sf::IntRect(0 * 54 + 18 * i, 0, 17, 32));
		_directionImages[DOWN][i].setTextureRect(sf::IntRect(2 * 54 + 18 * i, 0, 17, 32));
		_directionImages[LEFT][i].setTextureRect(sf::IntRect(3 * 54 + 18 * i, 0, 17, 32));
		_directionImages[RIGHT][i].setTextureRect(sf::IntRect(1 * 54 + 18 * i, 0, 17, 32));
	}
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
	/*if (!_map->isOutOfBound(x, y) && _map->isEmpty(x, y))
	{
		_map->removePlayer(_position._x, _position._y);
		_position._x = x;
		_position._y = y;
		_map->setPlayer(_position._x, _position._y, this);
	}*/

	if (++_step == 3)
		_step = 0;
}

//notifie quand une bombe explose et decremente les bombs en jeu
void Player::notifyBombExploded()
{
	_bombsInPlay--;
}

//dessine le player
void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::Sprite sprite = _directionImages[_currentDirection][_step];
	_scale->set(sprite, sf::Vector2i(_position._x, _position._y));
	target.draw(sprite);
}
