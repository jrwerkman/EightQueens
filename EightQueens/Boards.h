#pragma once
class Boards
{
	int dimension;
	Board *board;
public:
	Boards();
	Boards(const int dim);
	~Boards();

	void findOne();
	void findMany();
private:
	void init(const int dim);
};

