#include "Button.h"

Button::Button(const sf::Vector2f& pos)
{
	sprite.setPosition(pos);
}


void Button::draw(sf::RenderWindow & window)
{
	window.draw(sprite);
}

void Button::setStandardTexture(const TexutreIterator& texture)
{
	this->standardTexture = texture;
	this->sprite.setTexture(texture->second);
}

void Button::setButtonPointedTexture(const TexutreIterator& buttonPointedTexture) {
	this->buttonPointedTexture = buttonPointedTexture;
}

void Button::checkIfClicked(const InputManager& inputManager, const sf::RenderWindow & window)
{
	clicked = inputManager.isSpriteClicked(sprite, sf::Mouse::Button::Left, window);
}

void Button::checkIfPointed(const InputManager & inputManager, const sf::RenderWindow& window)
{
	wasPointed = pointed;
	pointed = inputManager.isMousePointingSprite(sprite, window);
}

void Button::update(DataPtr ptr)
{
	checkIfPointed(ptr->inputManager, ptr->window);
	checkIfClicked(ptr->inputManager, ptr->window);
	processTextureChanging();
}

void Button::setPosition(const sf::Vector2f& pos)
{
	sprite.setPosition(pos);
}

void Button::processTextureChanging()
{
	if (!wasPointed && pointed) {
		sprite.setTexture((*this->buttonPointedTexture).second);
	}
	else if (wasPointed && !pointed) {
		sprite.setTexture((*this->standardTexture).second);
	}
}

bool Button::isClicked()
{
	return clicked;
}
