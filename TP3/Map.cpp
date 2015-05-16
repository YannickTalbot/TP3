#include "Map.h"

Map::Map()
{
	init();
}

Map::~Map()
{
}

Player* Map::getPlayer(int x, int y) const
{
	// todo
	return NULL;
}

bool Map::isEmpty(int x, int y)
{
	//todo Verifier sil y a quelque chose dans la case
	return false;
}

//Initialise la map avec les valeurs de base
void Map::init()
{
	//Initialise le contour de la map avec des blocs indestructibles
	for (int i = 0; i < _size; i++)
	{
		_grid[0][i] = _grid[_size - 1][i] = _grid[i][0] = _grid[i][_size - 1] = square::indestructible;
	}

	//Initialise l'interieur de la map
	for (int i = 1; i < _size - 1; i++)
	{
		for (int j = 1; j < _size - 1; j++)
		{
			_grid[i][j] = (i % 2 == 0 && j % 2 == 0) ? square::indestructible : square::destructible;
		}
	}

	//Efface les blocs aux positions de départ
	for (int i = 0; i < 3; i++)
		_grid[i + 1][1] = _grid[1][i + 1] =	//Coin haut-gauche
		_grid[i + 1][_size - 2] = _grid[1][_size - 2 - i] =	//Coin bas-gauche
		_grid[_size - 2 - i][1] = _grid[_size - 2][i + 1] =	//Coin haut-droit
		_grid[_size - 2 - i][_size - 2] = _grid[_size - 2][_size - 2 - i] =	//Coin bas-droit
		square::vide;

	_grid[5][4] = square::vide;
}

//Getter
square::type Map::getSquare(int x, int y) const
{
	if (x >= _size || y >= _size)
		throw std::invalid_argument("Le carré à un index trop grand!");

	return _grid[x][y];
}

void Map::removeBreakableWall(int x, int y)
{
	//todo
}

void Map::setPlayer(int x, int y, Player *player)
{
	//todo
}

void Map::setBomb(Bomb bomb)
{
	bombs.push_back(bomb);
}

void Map::deleteSquare(int x, int y)
{
	if (_grid[x][y] == square::indestructible || isOutOfBound(x,y))
		throw std::invalid_argument("Le carré est indestructible");

	_grid[x][y] = square::vide;
}

bool Map::isEmpty(int x, int y)
{
	//todo Verifier sil y a quelque chose dans la case
	return false;
}
void Map::removePlayer(int x, int y)
{
	//todo
}

void Map::setFire(int x, int y, Fire fire)
{
	//todo
}

bool Map::isOutOfBound(int x, int y)
{
	return x < 0 || y < 0 || x >= _size || y >= _size;
}

bool Map::hasBomb(int x, int y)
{
	//todo
	return false;
}

//Dessine la map sur un rendertarget
void Map::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	//La grosseur finale de l'image sur un axe est donnée par imgSize * imgScale * res. 
	const int	imgSize = 30;			//Format de l'image sur la texture
	float		imgScale = .1602;		//Multiplicateur de la grosseur
	int			resVertical = 9;		//Multiplicateur de la résolution pour les y
	int			resHorizontal = 16;		//Multiplicateur de la résolution pour les x
	float		bombScale = 1;			//TODO


	//Chargement des textures
	sf::Texture texture;
	//Les carrés de la texture font tous ± 30 x 30 px
	texture.loadFromFile("./Images/mapTiles.bmp");

	//Création des sprites
	sf::Sprite vide, destructible, indestructible;
	vide.setTexture(texture);
	destructible.setTexture(texture);
	indestructible.setTexture(texture);

	//Assignation des positions de la texture aux sprites
	vide.setTextureRect(sf::IntRect(64, 0, imgSize, imgSize));
	destructible.setTextureRect(sf::IntRect(0, 32, imgSize, imgSize));
	indestructible.setTextureRect(sf::IntRect(0, 0, imgSize, imgSize));

	//Dessinnage de la map
	for (int i = 0; i < _size; i++)
	{
		for (int j = 0; j < _size; j++)
		{
			sf::Sprite sprite;	//Sprite à dessiner

			//Type de sprite a dessiner
			switch (_grid[i][j])
			{
			case square::vide:
				sprite = vide;
				break;
			case square::destructible:
				sprite = destructible;
				break;
			case square::indestructible:
				sprite = indestructible;
				break;
			default:
				break;
			}

			//Positionnement du sprite
			sprite.setScale(imgScale * resHorizontal, imgScale * resVertical);
			sprite.setPosition(imgSize * i * imgScale * resHorizontal, imgSize * j * imgScale * resVertical);

			//Dessin
			target.draw(sprite);
		}
	}

	//for (int i = 0; i < bombs.size(); i++)
	//{
	//	sf::Sprite sprite;
	//	sprite.setTexture(*bombs[i].getImage())

	//	sprite.setScale(imgScale * bombScale * resHorizontal, imgScale * bombScale * resVertical);
	//}
}

bool Map::hasPlayer(int x, int y)
{
	//todo
	return false;
}

bool Map::hasUnbreakableWall(int x, int y)
{
	//todo
	return false;
}

bool Map::hasBreakableWall(int x, int y)
{
	//todo
	return false;
}