#pragma once
#include <stack>
#include <SFML/Graphics.hpp>
#include "State.h"
#include <memory>

using StatePtr = std::unique_ptr<State>;

class StateMachine
{
public:
	StateMachine();

	void addState(StatePtr, bool replacing = true);
	void removeState();

	void processStateChanges();
	StatePtr& getActiveState();

private:

	void processAdding();
	void processRemoving();

	std::stack<StatePtr> states;
	StatePtr newState;
	bool isAdding = false;
	bool isRemoving = false;
	bool isReplacing = false;

};

