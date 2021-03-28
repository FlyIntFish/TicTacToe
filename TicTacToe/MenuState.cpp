#include "MenuState.h"
#include "Config.h"
#include "GameState.h"

MenuState::MenuState(DataPtr ptr)
{
	this->gameData = ptr;
}

void MenuState::update(const sf::Time& dt)
{
	exitButton.update(gameData);
	mapSize3Button.update(gameData);
	mapSize4Button.update(gameData);
	mapSize5Button.update(gameData);
}

void MenuState::draw()
{
	gameData->window.draw(sprite);
	mapSize3Button.draw(this->gameData->window);
	mapSize4Button.draw(this->gameData->window);
	mapSize5Button.draw(this->gameData->window);
	exitButton.draw(this->gameData->window);
	gameData->window.display();
}


void MenuState::handleInput()
{
	sf::Event event;
	while (gameData->window.pollEvent(event)) {
		if ((event.type == sf::Event::Closed) || exitButton.isClicked())
			gameData->window.close();
		if (mapSize3Button.isClicked())
			gameData->stateMachine.addState(std::make_unique<GameState>(gameData, 3));
		else if (mapSize4Button.isClicked())
			gameData->stateMachine.addState(std::make_unique<GameState>(gameData, 4));
		else if (mapSize5Button.isClicked())
			gameData->stateMachine.addState(std::make_unique<GameState>(gameData, 5));
	}
}

void MenuState::loadTextures() {
	gameData->assetManager.loadTexture(MENU_BUTTON_3X3_FILEPATH, MENU_BUTTON_3X3_NAME);
	gameData->assetManager.loadTexture(MENU_BUTTON_4X4_FILEPATH, MENU_BUTTON_4X4_NAME);
	gameData->assetManager.loadTexture(MENU_BUTTON_5X5_FILEPATH, MENU_BUTTON_5X5_NAME);
	gameData->assetManager.loadTexture(MENU_BUTTON_3X3_POINTED_FILEPATH, MENU_BUTTON_3X3_POINTED_NAME);
	gameData->assetManager.loadTexture(MENU_BUTTON_4X4_POINTED_FILEPATH, MENU_BUTTON_4X4_POINTED_NAME);
	gameData->assetManager.loadTexture(MENU_BUTTON_5X5_POINTED_FILEPATH, MENU_BUTTON_5X5_POINTED_NAME);
	gameData->assetManager.loadTexture(MENU_BUTTON_EXIT_POINTED_FILEPATH, MENU_BUTTON_EXIT_POINTED_NAME);
	gameData->assetManager.loadTexture(MENU_BUTTON_EXIT_FILEPATH, MENU_BUTTON_EXIT_NAME);
	gameData->assetManager.loadTexture(MENU_TEXTURE_FILEPATH, MENU_TEXTURE_NAME);
}

void MenuState::setTextures() 
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

void MenuState::initButtonsPosition() 
{
	mapSize3Button.setPosition(sf::Vector2f(373, 250));
	mapSize4Button.setPosition(sf::Vector2f(373, 350));
	mapSize5Button.setPosition(sf::Vector2f(373, 450));
	exitButton.setPosition(sf::Vector2f(373, 550));
}

void MenuState::init()
{
	loadTextures();
	setTextures();
	initButtonsPosition();

}
