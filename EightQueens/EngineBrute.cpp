#include "stdafx.h"
#include "EngineBrute.h"


EngineBrute::EngineBrute()
{
	init(DEFAULT_BOARD_SIZE);
}

EngineBrute::EngineBrute(const int &dim)
{
	init(dim);
}

EngineBrute::~EngineBrute()
{
	delete grid;
	delete possitions;
}

void EngineBrute::findSolution()
{
	//loopCombinations();

	int n = dimension;
	int k = dimension;
	int row, col;
	int cell;
	int rdiv;
	int nbr_comb = pow(k + 1, n);

	for (row = 0; row < nbr_comb; row++)
	{
		for (col = n - 1; col >= 0; col--)
		{
			rdiv = pow(k + 1, col);
			cell = (row / rdiv) % (k + 1);
			printf("%d |", cell);
		}
		printf("\n");
	}
}

void EngineBrute::init(const int & dim)
{
	dimension = dim;
	grid = new Grid(dimension);
	generatePositions();
}

void EngineBrute::generatePositions()
{
	// todo change to short int array witch stores the possition of the queen
	possitions = new short int[dimension];

	for (int i = 0; i < dimension; i++) 
		possitions[i] = i;

}

void EngineBrute::loopCombinations()
{
	// https://www.codesdope.com/blog/article/generating-permutations-of-all-elements-of-an-arra/
}

void EngineBrute::loopCombinations(short int data[], int start, int end, int index, int r)
{

}
