#include "MenuItem.h"

//Constructeur
MenuItem::MenuItem(std::string text, sf::Font *font , Position position, bool selectable)
{
	_text = text;
	_font = font;
	_position = position;
	_selectable = selectable;
}

//Destructeur
MenuItem::~MenuItem(){ }

//Getteurs
std::string MenuItem::getText() const
{
	return _text;
}

//Obtient la valeur de l'item sous la forme d'une string. Doit �tre surcharg�e dans les enfants
std::string MenuItem::getValue() const { return ""; }

//Change la valeur de l'item (pour ceux qui prennent des entr�es)
void MenuItem::changeValue(bool direction) { }

//Dessine l'item du menu. Doit �tre surcharg�e pour afficher la valeur actuelle dans les enfants
void MenuItem::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::Text text(_text, *_font, _position._size);
	text.setPosition(_position._x, _position._y);
	text.setColor(sf::Color(0, 0, 0, 255));
	

	//Cr�e un rectangle blanc � afficher derri�re le texte
	if (_selected)
	{
		text.setColor(sf::Color(255, 255, 255, 255));
		sf::RectangleShape background(sf::Vector2f(target.getSize().x, _position._size));
		background.setPosition(0,text.getPosition().y);
		background.setFillColor(sf::Color(0, 0, 0, 255));
		target.draw(background);
	}

	target.draw(text, states);
}
//Selectionne ou d�selectionne l'item
void MenuItem::selectionChange()
{
	if (!_selectable)
		throw std::runtime_error("Le menu essaye de s�lectionner un item qui ne devrais pas �tre s�lectionn�! -5 points pour nous");

	_selected = !_selected;
}