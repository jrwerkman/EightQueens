// EightQueens.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void solveOne(int dimension);
void solveMany(int dimension);

int main()
{
	solveOne(20);
	//solveMany(8);


	system("pause");
	//_CrtDumpMemoryLeaks();
	return 0;
}

void solveOne(int dim) {
	time_t start, end;
	printf("Looking for a solution to the [%d] queens problem.\n", dim);
	Boards problem(dim);

	time(&start);
	problem.findOne();
	time(&end);

	printf("Took [%.0f] seconds to calulate results \n", difftime(end, start));
}

void solveMany(int dim) {
	time_t start, end;
	printf("Looking for a solution to the [%d] queens problem.\n", dim);
	Boards problem(dim);

	time(&start);
	problem.findMany();
	time(&end);

	printf("Took [%.0f] seconds to calulate results \n", difftime(end, start));
}

