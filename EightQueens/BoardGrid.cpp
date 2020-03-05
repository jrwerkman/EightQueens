#include "stdafx.h"
#include "BoardGrid.h"


BoardGrid::BoardGrid()
{
}

BoardGrid::BoardGrid(const int dim)
{
	init(dim);
}


BoardGrid::~BoardGrid()
{
	for (int i = 0; i < dimension; i++)
		delete[] grid[i];

	delete[] grid;
}

void BoardGrid::init(const int dim)
{
	if (isInitialized)
		return;

	dimension = dim;

	grid = new unsigned char*[dimension];

	for (int i = 0; i < dimension; i++) {
		grid[i] = new unsigned char[dimension];

		for (int j = 0; j < dimension; j++)
			grid[i][j] = AVAILABLE;
	}

	isInitialized = true;
}

void BoardGrid::reinit()
{
	for (int i = 0; i < dimension; i++)
		for (int j = 0; j < dimension; j++)
			grid[i][j] = AVAILABLE;
}

void BoardGrid::copy(BoardGrid *gridToCopy)
{
	for (int x = 0; x < dimension; x++)
		for (int y = 0; y < dimension; y++)
			set(x, y, gridToCopy->get(x, y));
}

const unsigned char BoardGrid::get(const Coords coord)
{
	return get(coord.x, coord.y);
}

void BoardGrid::set(const Coords coord, const unsigned char type)
{
	set(coord.x, coord.y, type);
}

const unsigned char BoardGrid::get(const int x, const int y)
{
	return grid[x][y];
}

void BoardGrid::set(const int x, const int y, const unsigned char type)
{
	grid[x][y] = type;
}

bool BoardGrid::value(const Coords coord, const unsigned char type)
{
	return value(coord.x, coord.y, type);
}

bool BoardGrid::value(const int x, const int y, const unsigned char type)
{
	return get(x, y) == type;
}

void BoardGrid::print()
{
	print(false);
}

void BoardGrid::print(bool debug)
{
	for (int x = 0; x < dimension; x++) {
		for (int y = 0; y < dimension; y++) {
			unsigned char element = grid[x][y];

			if (!debug && element == NOT_POSSIBLE)
				element = UNAVAILABLE;

			printf("%c ", element);
		}

		printf("\n");
	}

	printf("\n");
}

