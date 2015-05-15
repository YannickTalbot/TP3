#pragma once

#include "Player.h"
#include "Bomb.h"
#include "Fire.h"

class Fire;
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

	//enleve le wall destructible a la position donnee
	void removeBreakableWall(int x, int y);

	//Ajoute un player a la position donnee
	void setPlayer(int x, int y, Player *player);

	//Place la bombe donnee a la position x,y
	void setBomb(int x, int y, Bomb bomb);

	//Place un feu a la position donne x ,y
	void setFire(int x, int y, Fire fire);

	//retourne vrai si la position donne est hors de la carte
	bool isOutOfBound(int x, int y);

	//retourne vrai si y a une bombe a une position donnee, faux sinon
	bool hasBomb(int x, int y);

	//retourne vrai si y a un player a une position donnee, faux sinon
	bool hasPlayer(int x, int y);

	//retourne vrai si y a un wall indestructible a la position donnee, faux sinon
	bool hasUnbreakableWall(int x, int y);

	//retourne vrai si y a un wall destructible a la position donnee, faux sinon
	bool hasBreakableWall(int x, int y);
};

