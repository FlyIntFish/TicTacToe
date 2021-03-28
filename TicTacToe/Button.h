#pragma once
#include <SFML/Graphics.hpp>
#include "GameData.h"

class Button
{
public:

	Button(DataPtr ptr);

	void draw();
	void setTextures(const std::string& texture, const std::string& buttonPointedTextureName);
	void update(const sf::Time & dt);

	bool isClicked();

private:

	void processTextureChanging();
	void checkIfClicked();
	void checkIfPointed();

	bool clicked;
	bool pointed;
	bool wasPointed;
	sf::Sprite sprite;
	std::map<std::string, sf::Texture>::const_iterator texture;
	std::map<std::string, sf::Texture>::const_iterator buttonPointedTexture;
	DataPtr gameDataPtr;

};

