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
	//delete gridList;
	delete possitions;
	delete state;
}

void EngineBrute::findSolution(GridList * list)
{
	permutation(list, possitions, 0, dimension-1);
	/*
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
	*/
}

void EngineBrute::init(const int & dim)
{
	dimension = dim;
	//gridList = new GridList();
	state = new State(dimension);
	generatePositions();
}

void EngineBrute::generatePositions()
{
	possitions = new int[dimension];

	for (int i = 0; i < dimension; i++) 
		possitions[i] = i;

}

//https://www.codesdope.com/blog/article/generating-permutations-of-all-elements-of-an-arra/ 
//function to swap the variables
void EngineBrute::swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

//permutation function
void EngineBrute::permutation(GridList * list, int *arr, int start, int end)
{
	if (start == end)
	{
		check(list, arr);
		return;
	}
	int i;
	for (i = start; i <= end; i++)
	{
		//swapping numbers
		swap((arr + i), (arr + start));
		//fixing one first digit
		//and calling permutation on
		//the rest of the digits
		permutation(list, arr, start + 1, end);
		swap((arr + i), (arr + start));
	}
}

void EngineBrute::check(GridList * list, int arr[])
{
	state->getGrid()->reinit();

	for (int i = 0; i < dimension; i++)
		if (!state->addQueen(Coords(i, arr[i])))
			return;

	list->insertEnd(*state->getGrid());
}
