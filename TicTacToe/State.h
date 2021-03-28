#pragma once
#include <SFML/Graphics.hpp>

class State
{
public:

	virtual void init() = 0;
	virtual void update(const sf::Time&) = 0;
	virtual void draw() = 0;
	virtual void handleInput() = 0;
	virtual void reasume() {}
	virtual void pause() {}

protected:

	virtual void loadTextures() {}
};