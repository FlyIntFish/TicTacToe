#include "Game.h"
#include "MenuState.h"

Game::Game(int width, int height, const std::string& title) {
	gameData = std::make_shared<GameData>();
	gameData->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
	run();
}

void Game::run() 
{
	sf::Time currentTime = clock.restart();
	sf::Time lastTime = currentTime;
	sf::Time accumulator;
	gameData->stateMachine.addState(std::make_unique<MenuState>(gameData), false);

	while (gameData->window.isOpen()) 
	{

		gameData->stateMachine.processStateChanges();
		currentTime = clock.getElapsedTime();
		sf::Time diff = currentTime - lastTime;
		if (diff > sf::seconds(0.2))
			diff = sf::seconds(0.2);
		accumulator += diff;
		lastTime = currentTime;

		while (accumulator >= frameRate) 
		{
			this->gameData->stateMachine.getActiveState()->update(accumulator);
			this->gameData->stateMachine.getActiveState()->handleInput();
			accumulator -= frameRate;
		}
		this->gameData->stateMachine.getActiveState()->draw();
	}
}