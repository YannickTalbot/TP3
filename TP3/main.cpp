/*Directives au préprocesseur
=============================*/
#include "Bomberman.h"
#include "Menu.h"
#include <iostream>


void main()
{
	sf::RenderWindow window;
	sf::VideoMode mode(1000, 600);
	ScaleInfo _scale;
	_scale.resHorizontal = 16;
	_scale.resVertical = 9;
	_scale.targetSize = 78;
	Map map/*_scale*/;
	window.create(mode, "BOOOOOOM!", sf::Style::Resize | sf::Style::Close);
	window.draw(map);
	window.display();

	system("pause");

}