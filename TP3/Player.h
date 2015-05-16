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
	enum Direction
	{
		UP = 0,
		DOWN = 1,
		LEFT = 2,
		RIGHT = 3
	};

	Position _position;
	Position _initialPosition;

	Map	*_map;

	sf::Image _directionImages[4];
	enum Direction _currentDirection;

	sf::Image _bombImage;
	
	int _lives;
	int _speed;
	int _power;

	int _maxBombsInPlay;	//how many at once
	int _bombsInPlay;

	void moveTo(int x, int y);
	void resetStats();
public:
	Player(); //Constructeur vide temporaire

	Player(Position initialPosition, Map *map, 
		sf::Image upImage, sf::Image downImage, 
		sf::Image leftImage, sf::Image rightImage);

	~Player();

	void kill();

	void placeBomb();

	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();

	void notifyBombExploded();

	sf::Image& getImage();
};

