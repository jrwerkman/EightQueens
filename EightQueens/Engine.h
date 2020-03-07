#pragma once
class Engine
{
	int dimension;
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
};

