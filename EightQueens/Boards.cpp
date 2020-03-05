#include "stdafx.h"
#include "Boards.h"


Boards::Boards()
{
	init(DEFAULT_BOARD_SIZE);
}

Boards::Boards(const int dim)
{
	init(dim);
}


Boards::~Boards()
{
	delete board;
}

void Boards::findOne()
{
	board->findSolution();
}

void Boards::findMany()
{
	for (int variation = 0; variation < dimension*dimension; variation++) {
		int x = variation / dimension;
		int y = variation % dimension;

		board->prepare(Coords(x, y));
		board->findSolution();
	}
}

void Boards::init(const int dim)
{
	dimension = dim;
	board = new Board(dim);
}
