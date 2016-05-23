#pragma once
class Position
{
public:
	int x;
	int y;

	Position();
	Position(int x, int y);

	// Overloaded ==, Are the two positions same?
	bool operator==(Position pos);
};

