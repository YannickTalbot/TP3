#pragma once
#include <SFML\Graphics.hpp>
#include "Position.h"

//
struct ScaleInfo {
	double		targetSize;			//Grosseur finale de l'image
	int			resVertical;		//Multiplicateur de la résolution pour les y
	int			resHorizontal;		//Multiplicateur de la résolution pour les x

	void set(sf::Sprite &sprite) const
	{
		//Formule pour les multiplicateur
		//targetSize = scale * texturerect
		//mult = targetSize  / textureRect

		float hScale = targetSize / sprite.getTextureRect().width;
		float vScale = targetSize / sprite.getTextureRect().height * resVertical / resHorizontal;

		sprite.setScale(hScale, vScale);
	}

};