#include "stdafx.h"

Engine::Engine()
{
	init(DEFAULT_BOARD_SIZE);
}

Engine::Engine(const int &dim)
{
	init(dim);
}

Engine::~Engine()
{
	delete gridList;
}

void Engine::setDimension(const int &dim)
{
	dimension = dim;
}

const int& Engine::getDimension()
{
	return dimension;
}

void Engine::stateFindOne()
{
	EngineState engineState(dimension);
	Grid* gridResult = engineState.findSolution();

	if (gridResult != nullptr)
		gridList->insertEnd(*gridResult);
}

void Engine::stateFindMany()
{
	EngineState engineState(dimension);

	for (int variation = 0; variation < dimension*dimension; variation++) {
		int x = variation / dimension;
		int y = variation % dimension;

		engineState.prepare(Coords(x, y));
		Grid* gridResult = engineState.findSolution();

		if (gridResult != nullptr)
			gridList->insertEnd(*gridResult);
	}
}

void Engine::bruteFindOne()
{
}

void Engine::bruteFindMany()
{
	EngineBrute engineBrute(dimension);

	engineBrute.findSolution();
}

void Engine::print() {
	for (int i = 0; i < gridList->size(); i++)
		gridList->get(i)->print();
}

const int Engine::results()
{
	return gridList->size();
}

void Engine::init(const int &dim) {
	gridList = new GridList();
	dimension = dim;
}