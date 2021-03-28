#pragma once
#include <SFML/Graphics.hpp>
#include "GameData.h"

class State
{
public:

	State(DataPtr ptr) { gameData = ptr; }

	virtual void init() = 0;
	virtual void update(const sf::Time&) = 0;
	virtual void draw() = 0;
	virtual void handleInput() = 0;
	virtual void reasume() {}
	virtual void pause() {}

private:

	DataPtr gameData;

};