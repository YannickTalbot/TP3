#pragma once
#include "Map.h"
#include "Player.h"
#include <vector>
#include <SFML\Window.hpp>

using namespace std;

class Bomberman
{
private:
	Map _map;
	vector<Player> _player;
	sf::Window _window;
	
	int _nbPlayer;
public:
	//Constructeurs 
	Bomberman();
	//Destructeur
	~Bomberman();

	//Initialisateurs (pour chaque partie)
	void init();

	//Cr�ation de joueurs
	void createPlayer();

	//Cr�ation de la map
	void createMap();

	//D�placement des personnages
	void movement();

	//Reddessinage de la map
	void drawMap();

	//Affiche un menu a choix multiples
	void menu();

	//Boucle de jeu principal
	void play();
};