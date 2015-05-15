/*Ce fichier contient les détails de l'interface
  des menus affichés par le jeu Bomberman.*/
#pragma once
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include <string>
#include <vector>
#include "MenuItem.h"
#include <SFML\Graphics\RenderStates.hpp>
#include <exception>

class Menu {
private:
	sf::RenderWindow _window;
	std::vector<MenuItem> _items;	//Items du menu
	sf::Font _font;

public:
	//Constructeur
	Menu();
	//Destructeur
	~Menu();

	//Place des items dans le menu
	void addItem(std::string text, types type, Position position);

	//Affiche la fenetre du menu
	void show(int page = 0);
};