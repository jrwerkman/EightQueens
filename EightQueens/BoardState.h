#pragma once

#include "Coords.h"

class BoardState
{
	int dimension;
	Coords lastCoords;
	BoardGrid grid;
public:
	BoardState();
	BoardState(const int dim);
	~BoardState();

	void init(const int dim);
	void copy(BoardState *boardStateToCopy);

	bool addQueen(const Coords coord);
	void addNotPossible(const Coords coord);

	Coords getLastCoords();
	BoardGrid* getGrid();

	bool isRowPossible(int row);
	bool isThereHope(int row);
private:
	void addUnavailable(const Coords coord);
	void addHorizontalUnavailable(const Coords coord);
	void addVerticalUnavailable(const Coords coord, const int x, const int y);
};

