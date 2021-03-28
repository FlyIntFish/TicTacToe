#include "StateMachine.h"
#include "StateMachine.h"
StateMachine::StateMachine(){
}

void StateMachine::addState(StatePtr newState, bool replacing) {
	this->isReplacing = replacing;
	this->isAdding = true;
	this->newState = (std::move(newState));
}

void StateMachine::removeState() {
	this->isRemoving = true;
}

void StateMachine::processStateChanges() {
	if (isAdding)
		processAdding();
	if (isRemoving) 
		processRemoving();
}


void StateMachine::processRemoving() {
		if (!states.empty())
			states.pop();
		if (!states.empty())
			states.top()->reasume();
		isRemoving = false;
	}

void StateMachine::processAdding(){
	if (isReplacing && !states.empty()) {
		states.pop();
		isReplacing = false;
	}
	else if (!states.empty()) {
		states.top()->pause();
	}
	states.push(std::move(newState));
	states.top()->init();
	isAdding = false;
}

StatePtr& StateMachine::getActiveState() {
	return states.top();
}