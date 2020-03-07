#pragma once

#include "Coords.h"

class State
{
	int dimension;
	Coords lastCoords;
	Grid grid;
public:
	State();
	State(const int &dim);
	~State();

	void init(const int &dim);
	void copy(State *boardStateToCopy);

	bool addQueen(const Coords &coord);
	void addNotPossible(const Coords &coord);

	Coords getLastCoords();
	Grid* getGrid();

	bool isRowPossible(const int &row);
	bool isThereHope(const int &row);
private:
	void addUnavailable(const Coords &coord);
	void addHorizontalUnavailable(const Coords &coord);
	void addVerticalUnavailable(const Coords &coord, const int &x, const int &y);
};

