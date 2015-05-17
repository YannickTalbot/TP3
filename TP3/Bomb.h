#pragma once
#include "position.h"
#include "Map.h"
#include "Player.h"
#include <SFML\Graphics.hpp>
#include <functional>

using namespace std;

class Map;
class Player;

class Bomb 
{
private:
	Position _position;
	Player* _player;
	Map* _map;
	int _power;
	int _fuse;
	sf::Image *_image;

	void explode();
	void drawFireLine(function<int&(Position&)> dimension, int direction);

public:
	Bomb();
	Bomb(sf::Image* image, Player* player, int power, Map* map);
	~Bomb();

	sf::Image* getImage() const;

	//la fuse a brule
	void tick();

	bool hasExploded();

	Position getPosition() const;

};

