#pragma once
class EngineBrute
{
	int dimension = 0;
	Grid * grid;
	short int * possitions;
public:
	EngineBrute();
	EngineBrute(const int &dim);
	~EngineBrute();

	void findSolution();
private:
	void init(const int &dim);
	void generatePositions();
	void loopCombinations();
	void loopCombinations(short int data[], int start, int end, int index, int r);
};

