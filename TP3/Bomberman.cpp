#include "Bomberman.h"

//Constructeur
Bomberman::Bomberman()
{		
	//Création de la fenetre
	sf::VideoMode mode(1000, 565);	//16:9
	_window.create(mode, "BOOOOOOM!", sf::Style::Resize | sf::Style::Close);
	
	//Permet que tout sois bien proportionné
	_scale.resHorizontal = 16;
	_scale.resVertical = 9;
	_scale.targetSize = 1000/13;	//Map de 13X13, écran de 1000x565

	_playerTexture.loadFromFile("./Images/Bomberman.gif");

	init();
}

Bomberman::~Bomberman()
{
}

//Initialise le jeu aux valeurs de départs
void Bomberman::init()
{
	_window.draw(_map);

	//Crée deux joueurs
	createPlayer(Position(1,1,20), &_map, _playerTexture);
	createPlayer(Position(12, 12, 20), &_map, _playerTexture);


}

//Crée des players
void Bomberman::createPlayer(Position initialPosition, Map *map, sf::Texture &texture)
{
	_player.push_back(Player(initialPosition, map, texture, &_scale));
}

//Commence la partie
void Bomberman::play()
{
	//Boucle principale
	while (_player.size() > 1)
	{

	}
}