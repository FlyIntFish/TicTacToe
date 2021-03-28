#pragma once
#include <SFML/Graphics.hpp>
#include "GameData.h"

using TexutreIterator = std::map<std::string, sf::Texture>::const_iterator;

class Button
{
public:

	Button(const sf::Vector2f& pos = sf::Vector2f(0,0));

	virtual void update(DataPtr ptr);
	virtual void setPosition(const sf::Vector2f& pos);
	virtual void draw(sf::RenderWindow& window);

	void setStandardTexture(const TexutreIterator& texture);
	void setButtonPointedTexture(const TexutreIterator& buttonPointedTexture);

	bool isClicked();

protected:

	virtual void processTextureChanging();

	void checkIfClicked(const InputManager& inputManager, const sf::RenderWindow& window);
	void checkIfPointed(const InputManager& inputManager, const sf::RenderWindow& window);

	bool clicked;
	bool pointed;
	bool wasPointed;
	sf::Sprite sprite;
	TexutreIterator standardTexture;
	TexutreIterator buttonPointedTexture;

};

