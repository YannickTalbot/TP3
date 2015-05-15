#pragma once

#include "Player.h"
#include "Bomb.h"
#include "SFML\Graphics.hpp"
#include <vector>

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

	//Efface le contenu d'un carré
	void deleteSquare(int x, int y);

	//retourne vrai sil ny a rien dans la case, faux sinon
	bool isEmpty(int x, int y);

	//enleve le player a la position donnee
	void removePlayer(int x, int y);

	//retourne vrai si la position donne est hors de la carte
	bool isOutOfBound(int x, int y);

	//retourne vrai si y a une bombe a une position donnee, faux sinon
	bool hasBomb(int x, int y);

	//Dessine la map
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};