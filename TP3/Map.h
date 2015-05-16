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
	static const int _size = 13;

	square::type _grid[_size][_size];

	std::vector<Bomb> _bombs;

public:
	Map();
	~Map();

	//Initialise la carte
	void init();

	//Getter
	square::type getSquare(const int x, const int y) const;

	//Setters
	//Ajoute un player a la position donnee
	void setPlayer(const int x, const int y, Player *player);

	//Place la bombe donnee 
	void setBomb(Bomb bomb);

	Player* getPlayer(const int x, const int y) const;

	//retourne vrai sil ny a rien dans la case, faux sinon
	bool isEmpty(const int x, const int y) const;

	//enleve le player a la position donnee
	void removePlayer(const int x, const int y);

	//enleve le wall destructible a la position donnee
	void removeBreakableWall(const int x, const int y);

	//Ajoute un player a la position donnee
	void setPlayer(const int x, const int y, const Player *player);

	//Place la bombe donnee a la position x,y
	void setBomb(const int x, const int y, const Bomb bomb);

	//Place un feu a la position donne x ,y
	void setFire(const int x, const int y, const Fire fire);

	//retourne vrai si la position donne est hors de la carte
	bool isOutOfBound(const int x, const int y) const;

	//retourne vrai si y a une bombe a une position donnee, faux sinon
	bool hasBomb(const int x, const int y) const;

	//retourne vrai si y a un player a une position donnee, faux sinon
	bool hasPlayer(const int x, const int y) const;

	//retourne vrai si y a un wall indestructible a la position donnee, faux sinon
	bool hasUnbreakableWall(const int x, const int y) const;

	//retourne vrai si y a un wall destructible a la position donnee, faux sinon
	bool hasBreakableWall(const int x, const int y) const;

	//Dessine la map
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};
