/*Contiens les items des menus.
==============================*/
#pragma once
#include <string>
#include <SFML\Graphics.hpp>
#include "Position.h"
#include <cassert>


enum types //Types d'item possible pour le menu
{
	MENU_ITEM_VOID, //Affichage seulement
	MENU_ITEM_INT,	//Entr�e de nombres (ex. nombre de joueurs)
	MENU_ITEM_BOOL,	//Entr�e de choses ayant deux valeurs possible (ex. Rejouer?)
};

/*Classe de base pour toutes les entr�es du menu. 
  Permet l'affichage de texte dans le menu, mais l'input doit se
  faire dans des classes d�riv�es */
class MenuItem : public sf::Drawable
{
protected:
	std::string _text;	//texte a afficher
	sf::Font *_font;	//font a utiliser
	Position _position;	//Position et grosseur du texte
	//Pour les �l�ments naviguables du menu
	bool _selectable;
	bool _selected = false;
public:
	//Constructeur
	MenuItem(std::string text, sf::Font *font,Position position, bool selectable);

	//Destructeur
	~MenuItem();

	//Getteurs
	std::string getText() const;

	//Obtient la valeur de l'item sous la forme d'une string. Doit �tre surcharg�e dans les enfants.
	virtual std::string getValue() const;

	//Change la valeur de l'item. Doit �tre surcharg�e dans les enfants, n'a aucun effet dans le parent.
	virtual void changeValue(bool direction);

	//Dessine l'item � l'�cran. Doit �tre surcharg�e dans les enfants.
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	//Selectionne ou d�selectionne l'item
	void selectionChange();
};

class MenuItemInt:public MenuItem
{
private: 
	int _value;
};