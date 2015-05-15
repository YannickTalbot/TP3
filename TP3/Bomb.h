#pragma once
#include "position.h"
#include "Player.h"
#include <SFML\Graphics.hpp>

class Player;

class Bomb 
{
private:
	Position _position;
	Player *_player;
	int _power;
	int _fuse;
	sf::Image *_image;
	void explode();

public:
	Bomb(sf::Image* image, Player* player, int power);
	~Bomb();

	sf::Image* getImage() const;

	//la fuse a brule
	void tick();

	bool hasExploded();

};

