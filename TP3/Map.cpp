#include "Map.h"

Map::Map()
{
	init();
}

Map::~Map()
{
}

//Wrong place?////////////////////////////////////////////////////////
//Je placerais tous les players dans bomberman.cpp, vu qu'ils sont déja storé la
Player* Map::getPlayer(const int x, const int y) const
{
	// todo
	return NULL;
}

void Map::setPlayer(const int x, const int y, Player *player)
{
	//todo
}

void Map::removePlayer(const int x, const int y)
{
	//todo
}

bool Map::hasPlayer(const int x, const int y) const
{
	//todo
	return false;
}


//Pourquoi on a pas une méthode draw dans bombs.cpp a la place?
void Map::setFire(const int x, const int y, const Fire fire)
{
	//todo
}
///////////////////////////////////////////////////////////////////

bool Map::isEmpty(const int x, const int y) const
{
	return _grid[x][y] == square::vide;
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
}

//Getter
square::type Map::getSquare(const int x, const int y) const
{
	if (isOutOfBound(x,y))
		throw std::invalid_argument("Le carré à un index invalide!");

	return _grid[x][y];
}

//Détruit un mur s'il est destructible, sinon cause une erreur
void Map::removeBreakableWall(const int x, const int y)
{
	if (isOutOfBound(x,y) || _grid[x][y] != square::destructible)
		throw std::invalid_argument("Le carré n'est pas destructible");
	
	_grid[x][y] = square::vide;
}

//Ajoute une bombe dans le vecteur bombs
void Map::setBomb(const Bomb bomb)
{
	_bombs.push_back(bomb);
}

//Vérifie si les coordonnées sont valide
bool Map::isOutOfBound(const int x, const int y) const
{
	return x < 0 || y < 0 || x >= _size || y >= _size;
}

//Vérifie si il y a une bombe aux coordonées données
bool Map::hasBomb(const int x, const int y) const
{
	bool bomb = false;

	for (int i = 0; i < _bombs.size(); i++)
		if (_bombs[i].getPosition()._x == x &&
			_bombs[i].getPosition()._y == y)
			bomb = true;

	return bomb;
}

//Dessine la map sur un rendertarget
void Map::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	ScaleInfo scale;
	scale.resHorizontal = 16;
	scale.resVertical = 9;
	scale.targetSize = 78;

	//La grosseur finale de l'image sur un axe est donnée par imgSize * imgScale * res. 
	const int	imgSize = 30;			//Format de l'image sur la texture
	double		imgScale = .1602;		//Multiplicateur de la grosseur
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
			scale.set(sprite, sf::Vector2i(i, j));

			//Dessin
			target.draw(sprite);
		}
	}
}

bool Map::hasUnbreakableWall(const int x, const int y) const
{
	return _grid[x][y] == square::indestructible;
}

bool Map::hasBreakableWall(const int x, const int y) const
{
	return _grid[x][y] == square::destructible;
}