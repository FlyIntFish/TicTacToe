#pragma once
#include "Button.h"

enum class PlayerType { O = 0, X = 1, none = 2 };

class BoardField : public Button
{
public:

	void update(DataPtr ptr);
	void setPosition(const sf::Vector2f& pos);
	void draw(sf::RenderWindow& window);

	void setXvalueTexture(const TexutreIterator& texture);
	void setOvalueTexture(const TexutreIterator& texture);

private:

	void processTextureChanging();

	TexutreIterator XvalueTexture;
	TexutreIterator OvalueTexture;
	sf::Sprite valueSprite;
	PlayerType value = PlayerType::none;

};

