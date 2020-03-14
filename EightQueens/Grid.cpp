#include "stdafx.h"

Grid::Grid()
{
	isInitialized = false;
}

Grid::Grid(const int &dim)
{
	init(dim);
}

Grid::Grid(const Grid &obj)
{
	dimension = obj.dimension;

	grid = new unsigned char*[dimension];

	for (int i = 0; i < dimension; i++) {
		grid[i] = new unsigned char[dimension];

		for (int j = 0; j < dimension; j++)
			grid[i][j] = obj.grid[i][j];
	}

	isInitialized = true;
}

Grid::~Grid()
{
	for (int i = 0; i < dimension; i++)
		delete[] grid[i];

	delete[] grid;
}

void Grid::init(const int &dim)
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

void Grid::reinit()
{
	for (int i = 0; i < dimension; i++)
		for (int j = 0; j < dimension; j++)
			grid[i][j] = AVAILABLE;
}

void Grid::copy(Grid *gridToCopy)
{
	for (int x = 0; x < dimension; x++)
		for (int y = 0; y < dimension; y++)
			set(x, y, gridToCopy->get(x, y));
}

const unsigned char& Grid::get(const Coords &coord)
{
	return get(coord.x, coord.y);
}

void Grid::set(const Coords &coord, const unsigned char &type)
{
	set(coord.x, coord.y, type);
}

const unsigned char& Grid::get(const int &x, const int &y)
{
	return grid[x][y];
}

void Grid::set(const int &x, const int &y, const unsigned char &type)
{
	grid[x][y] = type;
}

bool Grid::value(const Coords &coord, const unsigned char &type)
{
	return value(coord.x, coord.y, type);
}

bool Grid::value(const int &x, const int &y, const unsigned char &type)
{
	return get(x, y) == type;
}

bool Grid::compare(const Grid & obj)
{
	for (int x = 0; x < dimension; x++) 
		for (int y = 0; y < dimension; y++) 
			if (grid[x][y] == QUEEN && grid[x][y] != obj.grid[x][y])
				return false;

	return true;
}

void Grid::print()
{
	print(false);
}

void Grid::print(bool debug)
{
	for (int x = 0; x < dimension; x++) 
	{
		for (int y = 0; y < dimension; y++) 
		{
			unsigned char element = grid[x][y];

			if (!debug && element == NOT_POSSIBLE)
				element = UNAVAILABLE;

			printf("%c ", element);
		}

		printf("\n");
	}

	printf("\n");
}

