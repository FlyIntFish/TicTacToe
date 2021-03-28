#pragma once
#include <SFML/Graphics.hpp>
#include "GameData.h"

class Game
{
public:
	Game(int width, int height, const std::string& title = "Kolko i krzyzyk");

private:

	void run();

	sf::Clock clock;
	sf::Time frameRate = sf::seconds(1 / 60.f);
	DataPtr gameData;
	

};

