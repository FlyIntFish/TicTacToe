#pragma once
#include "State.h"
#include "Board.h"

class GameState : public State
{
public:

	GameState(DataPtr ptr, int boardSize);
	void handleInput();
	void update(const sf::Time& dt);
	void init();
	void draw();

private:
	
	void initPlayerTurnInfo();
	void changePlayer();
	void loadFont();
	void updatePlayerTurnInfo();
	void initBackgroundTexture();

	DataPtr gameData;
	Board board;
	PlayerType player;
	sf::Sprite background;
	sf::Text playerTurnInfo;
	PlayerType winner = PlayerType::none;

};

