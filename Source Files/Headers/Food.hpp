#pragma once
#include "Position.hpp"

class Food
{
public:
	// Spawn the food at a new location
	void SetPosition(int x, int y);
	// Get the position of the food
	Position GetPosition() { return myPosition; }

	Food();
	~Food();
private:
	// The position of the food
	Position myPosition;
};

