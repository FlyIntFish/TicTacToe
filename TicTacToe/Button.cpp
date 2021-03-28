#include "Button.h"

Button::Button(DataPtr ptr)
{
	this->gameDataPtr = ptr;
}

void Button::draw()
{
	gameDataPtr->window.draw(sprite);
}

void Button::setTextures(const std::string& textureName, const std::string& buttonPointedTextureName)
{
	this->buttonPointedTexture = gameDataPtr->assetManager.getTextureIterator(
								buttonPointedTextureName);
	this->texture = gameDataPtr->assetManager.getTextureIterator(textureName);
}

void Button::checkIfClicked()
{
	clicked = gameDataPtr->inputManager.isSpriteClicked(sprite, sf::Mouse::Button::Left,
		gameDataPtr->window);
}

void Button::checkIfPointed()
{
	wasPointed = pointed;
	pointed = gameDataPtr->inputManager.isMousePointingSprite(sprite, gameDataPtr->window);
}

void Button::update(const sf::Time& dt)
{
	checkIfPointed();
	checkIfClicked();
	processTextureChanging();
}

void Button::processTextureChanging()
{
	if (!wasPointed && pointed) {
		sprite.setTexture((*this->buttonPointedTexture).second);
	}
	else if (wasPointed && !pointed) {
		sprite.setTexture((*this->texture).second);
	}
}

bool Button::isClicked()
{
	return clicked;
}
