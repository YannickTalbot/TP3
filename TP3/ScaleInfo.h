#pragma once
#include <SFML\Graphics.hpp>
#include "Position.h"

//
struct ScaleInfo {
	double		targetSize;			//Grosseur finale de l'image
	int			resVertical;		//Multiplicateur de la résolution pour les y
	int			resHorizontal;		//Multiplicateur de la résolution pour les x

	//Ajuste les proportions pour que l'image finale aie la taille désirée
	void setScale(sf::Sprite &sprite) const
	{
		//Formule pour les multiplicateur
		//targetSize = scale * texturerect
		//mult = targetSize  / textureRect

		float hScale = targetSize / sprite.getTextureRect().width;
		float vScale = targetSize / sprite.getTextureRect().height * resVertical / resHorizontal;

		sprite.setScale(hScale, vScale);
	}

	//Positionne un objet selon ses coordonnées sur la map. Setter le scale avant de positionner
	void setPosition(sf::Sprite &sprite, const sf::Vector2i position) const
	{
		float x = sprite.getTextureRect().width * sprite.getScale().x * position.x;
		float y = sprite.getTextureRect().height * sprite.getScale().y * position.y;
		sprite.setPosition(x, y);
	}

	//Set le scale et la position
	void set(sf::Sprite &sprite, const sf::Vector2i position) const
	{
		setScale(sprite);
		setPosition(sprite, position);
	}
};