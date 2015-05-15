#pragma once

#include "Player.h"
#include "Bomb.h"

class Player;
class Bomb;

class Map
{
private:
	static const int _size = 10;

	int _grid[_size][_size];

public:
	Map();
	~Map();

	//Getter
	void getSquare(int x, int y) const;

	Player* getPlayer(int x, int y) const;

	//Efface le contenu d'un carré
	void deleteSquare(int x, int y);

	//Initialise la carte
	void init();

	//retourne vrai sil ny a rien dans la case, faux sinon
	bool isEmpty(int x, int y);

	//enleve le player a la position donnee
	void removePlayer(int x, int y);

	//Ajoute un player a la position donnee
	void setPlayer(int x, int y, Player *player);

	//Place la bombe donnee a la position x,y
	void setBomb(int x, int y, Bomb bomb);

	//retourne vrai si la position donne est hors de la carte
	bool isOutOfBound(int x, int y);

	//retourne vrai si y a une bombe a une position donnee, faux sinon
	bool hasBomb(int x, int y);

	bool hasPlayer(int x, int y);
};

