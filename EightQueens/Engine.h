#pragma once
class Engine
{
	int dimension;
	GridList *gridList;
public:
	Engine();
	Engine(const int &dim);
	~Engine();

	void setDimension(const int &dim);
	const int& getDimension();
	void stateFindOne();
	void stateFindMany();
	void bruteFindOne();
	void bruteFindMany();
	void print();
	const int results();
private:
	void init(const int &dim);
};

