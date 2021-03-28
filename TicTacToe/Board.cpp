#include "Board.h"
#include "Config.h"

Board::Board(DataPtr ptr): gameData(ptr)
{
}

const sf::Vector2f& Board::getPosition() const  {
	return board[0][0].getPosition();
}

void Board::init(int size) {
	createBoard(size);
	loadTextures();
	setTextures();
}

bool Board::handleInput(PlayerType player)
{
	for (auto& i : board) 
	{
		for (auto& j : i) 
		{
			if (j.isClicked() && !j.hasValue())
			{
				j.setValue(player);
				return true;
			}
		}
	}
	return false;
}

void Board::update()
{
	for (auto& i : board)
		for (auto& j : i)
			j.update(gameData);
}

PlayerType Board::commonValue(const BoardField& f1, const BoardField& f2, const BoardField& f3)
{
	if ((f1.getValue() == f2.getValue()) &&
		(f2.getValue() == f3.getValue()) &&
		(f1.getValue() != PlayerType::none))
		return f1.getValue();
	return PlayerType::none;
}

void Board::loadTextures()
{
	gameData->assetManager.loadTexture(FIELD_BUTTON_FILEPATH, FIELD_BUTTON_NAME);
	gameData->assetManager.loadTexture(FIELD_BUTTON_POINTED_FILEPATH, FIELD_BUTTON_POINTED_NAME);
	gameData->assetManager.loadTexture(FIELD_XVALUE_FILEPATH, FIELD_XVALUE_NAME);
	gameData->assetManager.loadTexture(FIELD_OVALUE_FILEPATH, FIELD_OVALUE_NAME);
	
}

void Board::setTextures()
{
	for (auto& i : board) {
		for (auto & j : i) {
			j.setStandardTexture(gameData->assetManager.getTextureIterator(FIELD_BUTTON_NAME));
			j.setButtonPointedTexture(gameData->assetManager.getTextureIterator(FIELD_BUTTON_POINTED_NAME));
			j.setOvalueTexture(gameData->assetManager.getTextureIterator(FIELD_OVALUE_NAME));
			j.setXvalueTexture(gameData->assetManager.getTextureIterator(FIELD_XVALUE_NAME));
		}
	}
}

void Board::createBoard(int size)
{
	this->size = size;
	for (int i = 0; i < size; ++i) {
		board.push_back(std::vector<BoardField>());
		for (int j = 0; j < size; ++j)
			board[i].push_back(BoardField());
	}
}

void Board::setPosition(const sf::Vector2f& pos)
{
	sf::Vector2f fieldDimensions = board[0][0].getDimensions();
	for (int i = 0; i < size; ++i) 
	{
		for (int j = 0; j < size; ++j)
		{
			board[i][j].setPosition(sf::Vector2f(
				pos.x + j * fieldDimensions.x,
				pos.y + i * fieldDimensions.y)
			);
		}
	}
}


void Board::draw() {
	for (auto& i : board)
		for (auto& j : i)
			j.draw(gameData->window);
}

PlayerType Board::checkWinner()
{
	for (int i = 0; i < size-2; ++i)
	{
		for (int j = 0; j < size-2; ++j)
		{
			PlayerType winner = commonValue(board[i][j], board[i + 1][j + 1], board[i + 2][j + 2]);
			if (winner != PlayerType::none)
				return winner;

		}
	}

	for (int i = 2; i < size; ++i)
	{
		for (int j = 0; j < size-2; ++j)
		{
			PlayerType winner = commonValue(board[i][j], board[i - 1][j + 1], board[i - 2][j + 2]);
			if (winner != PlayerType::none)
				return winner;

		}
	}

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size - 2; ++j)
		{
			PlayerType winner = commonValue(board[i][j], board[i][j + 1], board[i][j + 2]);
			if (winner != PlayerType::none)
				return winner;
		}
	}

	for (int i = 0; i < size - 2; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			PlayerType winner = commonValue(board[i][j], board[i + 1][j], board[i + 2][j]);
			if (winner != PlayerType::none)
				return winner;

		}
	}
	return PlayerType::none;
}
