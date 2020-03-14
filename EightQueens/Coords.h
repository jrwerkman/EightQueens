#pragma once
struct Coords
{
	Coords() {
	  x = 0;
	  y = 0;
	};

	Coords(int x, int y) {
		this->x = x;
		this->y = y;
	};

	Coords(const Coords &obj) {
		this->x = obj.x;
		this->y = obj.y;
	};

	bool inSquare(const int dim) {
		return x < dim && y < dim && x >= 0 && y >= 0;
	}

	int x;
	int y;
};