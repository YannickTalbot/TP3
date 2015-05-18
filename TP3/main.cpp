/*Directives au préprocesseur
=============================*/
#include "Bomberman.h"
#include "Menu.h"
#include <iostream>


void main()
{
	sf::RenderWindow window;
	sf::VideoMode mode(1000, 600);
	Map map;
	window.create(mode, "BOOOOOOM!", sf::Style::Resize | sf::Style::Close);
	window.draw(map);
	window.display();

	system("pause");
}