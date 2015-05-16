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
	sf::RenderWindow _window;
	
	int _nbPlayer;
public:
	//Constructeurs 
	Bomberman();
	//Destructeur
	~Bomberman();

	//Initialisateurs (pour chaque partie)
	void init();

	//Création de joueurs
	void createPlayer();

	//Boucle de jeu principal
	void play();
};