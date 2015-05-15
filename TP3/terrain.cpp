#include "terrain.h"

const int TILESIZE=0;//Grosseur d'un carré de terrain

//Constructeurs*******************************************************************************************************************
terrain::terrain(const sf::Texture *texture, sf::Rect<int> position)
{
	_texture = texture;
	_position = position;
}
terrain::terrain(const sf::Texture *texture, int x, int y)
{
	_texture = texture;
	_position.left = x;
	_position.top = y;
	_position.height = _position.width = TILESIZE;
}
//Destructeur
terrain::~terrain()
{
}

bool terrain::collision(sf::Rect<int> personnage) { return !_traversable && _position.intersects(personnage); }
