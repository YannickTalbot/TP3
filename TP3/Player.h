#pragma once

#include "position.h"
#include "Bomb.h"
#include <vector>
#include <SFML\Graphics.hpp>
#include "Map.h"

using namespace std;

class Map;

class Player:public sf::Drawable
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

	sf::Sprite _directionImages[4][3];
	enum Direction _currentDirection;

	sf::Sprite _bombImage;
	
	int _lives;
	int _speed;
	int _power;

	int _maxBombsInPlay;	//how many at once
	int _bombsInPlay;
	int _step = 0;

	void moveTo(const int x, const int y);
	void resetStats();
public:
	Player(); //Constructeur vide 

	Player(Position initialPosition, Map *map, sf::Texture &texture);

	~Player();

	void kill();

	void placeBomb();

	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();

	void notifyBombExploded();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	//sf::Sprite& getImage();
};

