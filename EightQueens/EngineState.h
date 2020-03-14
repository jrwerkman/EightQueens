#pragma once
class EngineState
{
	int currentState;
	int numberOfStates;
	int dimension;
	State *states;
public:
	EngineState();
	EngineState(const int &dim);
	~EngineState();

	void findSolution(GridList * list);
	void reinit();
	void prepare(const Coords &coord);
private:
	int& getDimension();
	bool checkNext(const int &state);
	int getContinuationState(const int &currentState);
	void init(const int &dim);
};

