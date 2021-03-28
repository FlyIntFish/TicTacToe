#pragma once
#include "InputManager.h"
#include "AssetManager.h"
#include "StateMachine.h"
#include <SFML/Window.hpp>
#include <memory>

class GameData {
public:

	GameData(const GameData&) = delete;
	GameData(GameData&&) = delete;
	GameData() {}

	GameData& operator=(const GameData&) = delete;

	InputManager inputManager;
	AssetManager assetManager;
	StateMachine stateMachine;
	sf::RenderWindow window;

};

using DataPtr = std::shared_ptr<GameData>;

