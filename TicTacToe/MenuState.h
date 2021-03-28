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

private:

	void loadTextures();
	void setTextures();
	void initButtonsPosition();

	DataPtr gameData;
	sf::Sprite sprite;
	Button mapSize3Button; // used to choose size of map - 3x3, 4x4, 5x5
	Button mapSize4Button;
	Button mapSize5Button;
	Button exitButton;


};

