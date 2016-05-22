#pragma once
#include <vector>
#include "Position.hpp"
#include "PixelMap.hpp"

using namespace std;

class Snake
{
public:
	// The direction enum
	enum Direction { Up = -2, Left, Right = 1, Down };
	
	// Move ahead in the current direction
	bool MoveAhead();
	// Increase the size of the snake
	void IncreaseSize();
	// Change the direction of the snake
	void ChangeDirection(Direction direction);

	// Get the position of the snake
	vector<Position> GetPosition() { return myBodyPosition; }
	// Get the direction of the snake
	Direction GetDirection() { return myDirection; }

	Snake(vector<Position> position, Direction direction);
private:
	// The size of the snake
	int mySize;
	// The direction at which the snake is facing
	Direction myDirection;
	// The direction to move next time if possible
	Direction myDirectionToMove;

	// The position of the last piece
	Position lastPiece;

	// The vector storing the position of the body of the snake
	vector<Position> myBodyPosition;
};