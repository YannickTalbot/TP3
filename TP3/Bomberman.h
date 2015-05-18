#pragma once
#include "Map.h"
#include "Player.h"
#include <vector>
#include <memory>
#include <SFML\Window.hpp>

using namespace std;

class Bomberman :public sf::Drawable
{
private:
	ScaleInfo _scale;
	Map _map;

	vector<unique_ptr<Player>> _player;
	vector<Bomb> _bombs;
	sf::RenderWindow _window;
	sf::Texture _playerTexture;

	int _nbPlayer;
public:
	//Constructeurs 
	Bomberman();
	//Destructeur
	~Bomberman();

	//Initialisateurs (pour chaque partie)
	void init();

	//Création de joueurs
	void createPlayer(Position initialPosition);

	//Boucle de jeu principal
	void play();

	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};