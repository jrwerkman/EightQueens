#pragma once

#include "Coords.h"

class BoardGrid
{
	bool isInitialized = false;
	unsigned char **grid;
	int dimension;
public:
	BoardGrid();
	BoardGrid(const int dim);
	~BoardGrid();

	void init(const int dim);
	void reinit();
	void copy(BoardGrid *gridToCopy);

	const unsigned char get(const Coords coord);
	void set(const Coords coord, const unsigned char type);

	const unsigned char get(const int x, const int y);
	void set(const int x, const int y, const unsigned char type);

	bool value(const Coords coord, const unsigned char type);
	bool value(const int x, const int y, const unsigned char type);

	void print();
	void print(bool debug);
};

