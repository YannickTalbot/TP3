#include "Bomberman.h"

//Constructeur
Bomberman::Bomberman()
{		
	//Création de la fenetre
	sf::VideoMode mode(800, 600);
	_window.create(mode, "BOOOOOOM!", sf::Style::Resize | sf::Style::Close);
	_window.display();
}


Bomberman::~Bomberman()
{
}

void Bomberman::createPlayer()
{
}