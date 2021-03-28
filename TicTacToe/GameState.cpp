#include "GameState.h"
#include "Config.h"
GameState::GameState(DataPtr ptr, int boardSize) : gameData(ptr), board(ptr), player(PlayerType::O)
{
	board.init(boardSize);
	board.setPosition(sf::Vector2f(BOARD_X_POS, BOARD_Y_POS));
}

void GameState::handleInput()
{
	sf::Event event;
	while (gameData->window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			gameData->window.close();
		}
		if ((winner == PlayerType::none) && board.handleInput(this->player)) 
		{
			changePlayer();
		}
	}
}

void GameState::update(const sf::Time& dt)
{
	board.update();
	winner = board.checkWinner();
	updatePlayerTurnInfo();
}

void GameState::init()
{
	initBackgroundTexture();
	initPlayerTurnInfo();
}

void GameState::draw()
{
	gameData->window.clear();
	gameData->window.draw(background);
	gameData->window.draw(playerTurnInfo);
	board.draw();
	gameData->window.display();
}

void GameState::initPlayerTurnInfo()
{
	loadFont();
	updatePlayerTurnInfo();
	playerTurnInfo.setCharacterSize(TURN_INFO_CHAR_SIZE);
	playerTurnInfo.setFillColor(sf::Color::Black);
	playerTurnInfo.setPosition(board.getPosition().x, board.getPosition().y - 1.5*playerTurnInfo.getGlobalBounds().height);
}

void GameState::changePlayer()
{
	if (player == PlayerType::O)
		player = PlayerType::X;
	else
		player = PlayerType::O;
}

void GameState::loadFont() {
	gameData->assetManager.loadFont(GAME_FONT_FILEPATH, GAME_FONT_NAME);
	playerTurnInfo.setFont(gameData->assetManager.getFont(GAME_FONT_NAME));
}

void GameState::updatePlayerTurnInfo()
{
	if (player == PlayerType::O)
		playerTurnInfo.setString("ruch wykonuje: O");
	else
		playerTurnInfo.setString("ruch wykonuje: X");
	if(winner == PlayerType::O)
		playerTurnInfo.setString("Zwyciezyl gracz: O!");
	else if (winner == PlayerType::X)
		playerTurnInfo.setString("Zwyciezyl gracz: X!");
}

void GameState::initBackgroundTexture()
{
	gameData->assetManager.loadTexture(GAME_BACKGROUND_FILEPATH, GAME_BACKGROUND_NAME);
	background.setTexture(gameData->assetManager.getTexture(GAME_BACKGROUND_NAME));
}
