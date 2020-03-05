#pragma once
class Board
{
	int currentState = 0;
	int numberOfStates = 0;
	int dimension = 0;
	BoardState *states = nullptr;
public:
	Board();
	Board(const int dim);
	~Board();

	void findSolution();
	void reinit();
	void prepare(const Coords coord);
private:
	int getDimension();
	bool checkNext(const int state);
	int getContinuationState(const int state);
	void init(const int dim);
};

