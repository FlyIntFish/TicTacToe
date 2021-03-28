#include "MenuState.h"
#include "Config.h"

void MenuState::update(const sf::Time& dt)
{
}

void MenuState::draw()
{
	gameData->window.draw(sprite);
	mapSize3Button.draw(this->gameData->window);
	mapSize4Button.draw(this->gameData->window);
	mapSize5Button.draw(this->gameData->window);
	exitButton.draw(this->gameData->window);
}

void MenuState::handleInput()
{
	if (exitButton.isClicked())
		; // program end

}

void MenuState::loadTextures() {
	gameData->assetManager.loadTexture(MENU_BUTTON_3X3_FILEPATH, MENU_BUTTON_3X3_NAME);
	gameData->assetManager.loadTexture(MENU_BUTTON_4X4_FILEPATH, MENU_BUTTON_4X4_NAME);
	gameData->assetManager.loadTexture(MENU_BUTTON_5X5_FILEPATH, MENU_BUTTON_5X5_NAME);
	gameData->assetManager.loadTexture(MENU_BUTTON_EXIT_POINTED_FILEPATH, MENU_BUTTON_EXIT_NAME);
	gameData->assetManager.loadTexture(MENU_TEXTURE_FILEPATH, MENU_TEXTURE_FILEPATH);
}

void MenuState::init()
{

	this->mapSize3Button.setStandardTexture(gameData->assetManager.getTextureIterator(MENU_BUTTON_3X3_NAME));
	this->mapSize3Button.setButtonPointedTexture(gameData->assetManager.getTextureIterator(MENU_BUTTON_3X3_POINTED_NAME));
	this->mapSize4Button.setStandardTexture(gameData->assetManager.getTextureIterator(MENU_BUTTON_4X4_NAME));
	this->mapSize4Button.setButtonPointedTexture(gameData->assetManager.getTextureIterator(MENU_BUTTON_4X4_POINTED_NAME));
	this->mapSize5Button.setStandardTexture(gameData->assetManager.getTextureIterator(MENU_BUTTON_5X5_NAME));
	this->mapSize5Button.setButtonPointedTexture(gameData->assetManager.getTextureIterator(MENU_BUTTON_5X5_POINTED_NAME));
	this->sprite.setTexture(gameData->assetManager.getTexture(MENU_TEXTURE_NAME));
	this->exitButton.setStandardTexture(gameData->assetManager.getTextureIterator(MENU_BUTTON_EXIT_NAME));
	this->exitButton.setButtonPointedTexture(gameData->assetManager.getTextureIterator(MENU_BUTTON_EXIT_POINTED_NAME));

}
