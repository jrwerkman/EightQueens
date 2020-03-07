#include "stdafx.h"

State::State()
{

}

State::State(const int &dim)
{
	grid.init(dim);
}

State::~State()
{
}

void State::init(const int &dim)
{
	dimension = dim;
	grid.init(dim);
}

void State::copy(State *boardStateToCopy)
{
	dimension = boardStateToCopy->dimension;
	lastCoords = boardStateToCopy->lastCoords;
	grid.copy(&boardStateToCopy->grid);
}


bool State::addQueen(const Coords &coord)
{
	if (coord.x >= dimension || coord.y >= dimension)
		return false;

	if (grid.value(coord, AVAILABLE)) {
		lastCoords = coord;
		addUnavailable(coord);
		grid.set(coord, QUEEN);

		return true;
	}

	return false;
}


void State::addNotPossible(const Coords &coord)
{
	grid.set(coord, NOT_POSSIBLE);
}

Coords State::getLastCoords()
{
	return lastCoords;
}

Grid* State::getGrid()
{
	return &grid;
}

bool State::isRowPossible(const int &row)
{
	if (row == dimension)
		return false;

	for (int i = 0; i < dimension; i++)
		if (grid.value(row, i, AVAILABLE))
			return true;

	return false;
}

bool State::isThereHope(const int &row)
{
	if (row == dimension)
		return false;

	int amountUnavailable = 0;
	for (int i = 0; i < dimension; i++)
		if (grid.value(row, i, NOT_POSSIBLE))
			amountUnavailable++;;

	return amountUnavailable != dimension;
}

void State::addUnavailable(const Coords &coord)
{
	addHorizontalUnavailable(coord);
	addVerticalUnavailable(coord, 1, 1);
	addVerticalUnavailable(coord, 1, -1);
	addVerticalUnavailable(coord, -1, 1);
	addVerticalUnavailable(coord, -1, -1);
}

void State::addHorizontalUnavailable(const Coords &coord)
{
	for (int i = 0; i < dimension; i++) {
		if (grid.value(coord.x, i, AVAILABLE))
			grid.set(coord.x, i, UNAVAILABLE);

		if (grid.value(i, coord.y, AVAILABLE))
			grid.set(i, coord.y, UNAVAILABLE);
	}
}

void State::addVerticalUnavailable(const Coords &coord, const int &x, const int &y)
{
	int addX = 0;
	int addY = 0;

	while (true) {
		addX += x;
		addY += y;

		Coords newCoords(coord.x + addX, coord.y + addY);

		// TODO
		// TODO
		// TODO
		// TODO
		// TODO
		if (!newCoords.inSquare(dimension))
			break;

		if (grid.value(newCoords, AVAILABLE))
			grid.set(newCoords, UNAVAILABLE);
	}
}
