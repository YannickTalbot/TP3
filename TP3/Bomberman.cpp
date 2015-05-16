#include "Bomberman.h"

//Constructeur
Bomberman::Bomberman()
{		
	//Création de la fenetre
	sf::VideoMode mode(1000, 600);
	_window.create(mode, "BOOOOOOM!", sf::Style::Resize | sf::Style::Close);

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
	createPlayer();
	createPlayer();
}

//Crée des players
void Bomberman::createPlayer()
{
	_player.push_back(Player());
}

//Commence la partie
void Bomberman::play()
{
	//Boucle principale
	while (_player.size() > 1)
	{

	}
}