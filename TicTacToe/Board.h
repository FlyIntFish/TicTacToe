#pragma once
#include "BoardField.h"
#include <array>

class Board
{

public:

	Board(DataPtr ptr);

	const sf::Vector2f& getPosition() const;

	void draw();
	void init(int size);
	bool handleInput(PlayerType player);
	void update();
	void setPosition(const sf::Vector2f& pos);
	PlayerType checkWinner();

private:

	PlayerType commonValue(const BoardField& f1, const BoardField& f2, const BoardField& f3);
	void loadTextures();
	void setTextures();
	void createBoard(int size);

	DataPtr gameData;
	std::vector<std::vector<BoardField>> board;
	int size;

};

