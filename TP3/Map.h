#pragma once

#include "Player.h"
#include "Bomb.h"
#include "Fire.h"
#include "SFML\Graphics.hpp"
#include <vector>

class Fire;
class Player;
class Bomb;

namespace square {
	enum type {
		indestructible = 2,
		destructible = 1,
		vide = 0
	};
}

class Map :public sf::Drawable
{
private:
	static const int _size = 10;

	square::type _grid[_size][_size];

	vector<Bomb> bombs;

public:
	Map();
	~Map();

	//Initialise la carte
	void init();

	//Getter
	square::type getSquare(int x, int y) const;

	//Setters
	//Ajoute un player a la position donnee
	void setPlayer(int x, int y, Player *player);

	//Place la bombe donnee 
	void setBomb(Bomb bomb);

	Player* getPlayer(int x, int y) const;

	//Efface le contenu d'un carré
	void deleteSquare(int x, int y);

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

	//Dessine la map
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};
