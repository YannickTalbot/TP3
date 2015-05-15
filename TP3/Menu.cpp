#include "Menu.h"

Menu::Menu()
{
	sf::VideoMode mode(800, 600, 32U);
	_window.create(mode, "Menu", 7U, sf::ContextSettings(0U, 0U, 0U, 2U, 0U));

	_font.loadFromFile(".\\Fonts\\ArcadeClassic.ttf");
}

Menu::~Menu(){ }

void Menu::addItem(std::string text, types type, Position position)
{
	//Ajoute du texte qui ne prend pas d'entrée au menu
	if (type == MENU_ITEM_VOID)
		_items.push_back(MenuItem(text, &_font, position, true));
}

//Affiche la fenetre du menu
void Menu::show(int page)
{	
	//Couleur du fond
	sf::RectangleShape background;
	const int MAX_PER_PAGE = 5;
	//Le nombre d'item sur la page
	int itemsOnPage = (page == (_items.size() / MAX_PER_PAGE)) ? (_items.size() % MAX_PER_PAGE) : MAX_PER_PAGE;
	
	background.setFillColor(sf::Color(255, 255, 255));
	background.setSize(sf::Vector2f(_window.getSize().x,_window.getSize().y));
	_window.draw(background);

	_items[1].selectionChange();

	for (int i = 0; i < itemsOnPage; i++)
	{
		_window.draw(_items[page * MAX_PER_PAGE + i]);
	}

	_window.display();
}