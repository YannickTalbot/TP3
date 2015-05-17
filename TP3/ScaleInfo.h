#pragma once
#include <SFML\Graphics.hpp>

//
struct ScaleInfo {
	double		targetSize;			//Grosseur finale de l'image
	int			resVertical;		//Multiplicateur de la résolution pour les y
	int			resHorizontal;		//Multiplicateur de la résolution pour les x

	void setScale(sf::Sprite &sprite) const
	{
		float hScale = targetSize / sprite.getTextureRect().width;
		float vScale = targetSize / sprite.getTextureRect().height;
		sprite.setScale(hScale * resHorizontal, (float)imgScale * resVertical);
	}
};