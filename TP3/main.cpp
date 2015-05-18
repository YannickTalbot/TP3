/*Directives au préprocesseur
=============================*/
#include "Bomberman.h"
#include "Player.h"
#include <iostream>


void main()
{
	sf::RenderWindow window;
	sf::VideoMode mode(1000, 600);
	ScaleInfo _scale;
	_scale.resHorizontal = 16;
	_scale.resVertical = 9;
	_scale.targetSize = 78;
	Map map;
	sf::Texture texture;
	texture.loadFromFile("./Images/Bomberman.gif");

	window.create(mode, "BOOOOOOM!", sf::Style::Resize | sf::Style::Close);
	window.draw(map);

	Player player(Position(), &map, texture);
	window.draw(player);

	window.display();

	window.setKeyRepeatEnabled(false);
	sf::Event event;
	while (true)
	{
		window.pollEvent(event);
		if (event.type == sf::Event::EventType::KeyPressed)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Up:
				player.moveUp();
				break;
			case sf::Keyboard::Down:
				player.moveDown();
				break;
			case sf::Keyboard::Left:
				player.moveLeft();
				break;
			case sf::Keyboard::Right:
				player.moveRight();
				break;
			case sf::Keyboard::Escape:
				exit(0);
			default:
				break;
			}

			window.draw(map);
			window.draw(player); 
			window.display();
		}
	}


}