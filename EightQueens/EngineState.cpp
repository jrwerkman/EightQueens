#include "stdafx.h"

EngineState::EngineState()
{
	init(DEFAULT_BOARD_SIZE);
}

EngineState::EngineState(const int &dim)
{
	init(dim);
}

EngineState::~EngineState()
{
	if(states != nullptr)
		delete[] states;
}

void EngineState::init(const int &dim)
{
	dimension = dim;
	numberOfStates = dim + 1;

	states = new State[numberOfStates];

	for (int i = 0; i < numberOfStates; i++)
		states[i].init(dimension);
}

int& EngineState::getDimension()
{
	return dimension;
}

bool EngineState::checkNext(const int &state)
{
	int row = state - 1;
	bool success = false;

	for (int column = 0; column < dimension; column++) {
		success = states[state].addQueen(Coords(row, column));

		if (success)
			break;
	}

	return success;
}

int EngineState::getContinuationState(const int &currentState)
{
	for (int i = currentState - 1; i > 0; i--)
		if (i != 0 && states[i].isRowPossible(i))
			return i;

	return 0;
}

Grid* EngineState::findSolution() {
	bool foundSolution = true;

	for (int state = 1; state < numberOfStates; state++) {
		if (!states[state].isThereHope(state - 1)) {
			foundSolution = false;
			break;
		}

		if (!checkNext(state)) {
			state = getContinuationState(state);

			states[state].addNotPossible(
				states[state + 1].getLastCoords());

			states[state + 1].copy(&states[state]);
		}
		else if (state < dimension)
		{
			states[state + 1].copy(&states[state]);
		}
	}

	if (foundSolution)
		return states[numberOfStates - 1].getGrid();

	return nullptr;
}

void EngineState::reinit()
{
	for (int i = 0; i < numberOfStates; i++)
		states[i].getGrid()->reinit();
}

void EngineState::prepare(const Coords &coord)
{
	reinit();
	states[0].addRestriction(coord);
	states[1].copy(&states[0]);
}


