#pragma once

#include "position.h"
#include "Bomb.h"
#include <vector>
#include <SFML\Graphics.hpp>
#include "Map.h"

using namespace std;

class Map;

class Player
{
private:
	Position _position;
	Position _initialPosition;
	Map	*_map;
	int _directionImg;
	int _lives;
	int _speed;
	int _power;
	int _maxBombsInPlay;	//how many at once
	sf::Image _bombImage;
	
	int _bombsInPlay;

	void moveTo(int x, int y);
	void resetStats();
public:
	Player(Position initialPosition, Map *map);
	~Player();

	void kill();

	void placeBomb();

	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();

	void notifyBombExploded();
};

