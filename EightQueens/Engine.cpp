#include "stdafx.h"


Engine::Engine()
{
	dimension = DEFAULT_BOARD_SIZE;
}

Engine::Engine(const int &dim)
{
	dimension = dim;
}


Engine::~Engine()
{

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
	engineState.findSolution();
}

void Engine::stateFindMany()
{
	EngineState engineState(dimension);

	for (int variation = 0; variation < dimension*dimension; variation++) {
		int x = variation / dimension;
		int y = variation % dimension;

		engineState.prepare(Coords(x, y));
		engineState.findSolution();
	}
}

void Engine::bruteFindOne()
{
}

void Engine::bruteFindMany()
{
}
