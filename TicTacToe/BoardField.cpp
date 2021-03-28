#include "BoardField.h"

const sf::Vector2f& BoardField::getPosition() const
{
	return sprite.getPosition();
}

PlayerType BoardField::getValue() const
{
	return value;
}

void BoardField::setValue(PlayerType val)
{
	this->value = val;
	if (val == PlayerType::O)
		valueSprite.setTexture(OvalueTexture->second);
	if(val == PlayerType::X)
		valueSprite.setTexture(XvalueTexture->second);
}


void BoardField::setPosition(const sf::Vector2f& pos)
{
	Button::setPosition(pos);
	valueSprite.setPosition(pos);
}

void BoardField::draw(sf::RenderWindow& window)
{
	Button::draw(window);
	window.draw(this->valueSprite);
}

bool BoardField::hasValue()
{
	return value != PlayerType::none;
}

void BoardField::setXvalueTexture(const TexutreIterator& texture)
{
	this->XvalueTexture = texture;
}

void BoardField::setOvalueTexture(const TexutreIterator& texture)
{
	this->OvalueTexture = texture;
}

void BoardField::processTextureChanging()
{
	if (value == PlayerType::none) {
		Button::processTextureChanging();
	}
}
