#pragma once

#include "Coords.h"

class Grid
{
	bool isInitialized = false;
	unsigned char **grid;
	int dimension;
public:
	Grid();
	Grid(const int &dim);
	Grid(const Grid &obj);
	~Grid();

	void init(const int &dim);
	void reinit();
	void copy(Grid *gridToCopy);

	const unsigned char& get(const Coords &coord);
	void set(const Coords &coord, const unsigned char &type);

	const unsigned char& get(const int &x, const int &y);
	void set(const int &x, const int &y, const unsigned char &type);

	bool value(const Coords &coord, const unsigned char &type);
	bool value(const int &x, const int &y, const unsigned char &type);

	void print();
	void print(bool debug);
};

