#pragma once
class EngineBrute
{
	int dimension = 0;
	//GridList * gridList;
	State *state;
	int * possitions;
public:
	EngineBrute();
	EngineBrute(const int &dim);
	~EngineBrute();

	void findSolution(GridList * list);
private:
	void init(const int &dim);
	void generatePositions();
	void swap(int *a, int *b);
	void permutation(GridList * list, int *arr, int start, int end);
	void check(GridList * list, int arr[]);
};

