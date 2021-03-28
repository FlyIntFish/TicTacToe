#pragma once
#include "State.h"
#include "Button.h";

class MenuState : public State{

public:

	MenuState(DataPtr ptr);

	void init();
	void update(const sf::Time& dt);
	void draw();
	void handleInput();
	void reasume();
	void pause();


private:

	sf::Sprite sprite;
	Button mapSize3; // used to choose size of map - 3x3, 4x4, 5x5
	Button mapSize4;
	Button mapSize5;

};

