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
	void addRestriction(const Coords &coord);

	Coords getLastCoords();
	Grid* getGrid();

	bool isRowPossible(const int &row);
	bool isThereHope(const int &row);
private:
	void addUnavailable(const Coords &coord);
	void addState(const Coords &coord, unsigned char type);
	void addHorizontalUnavailable(const Coords &coord, unsigned char &type);
	void addVerticalUnavailable(const Coords &coord, unsigned char &type, const int &x, const int &y);
};

