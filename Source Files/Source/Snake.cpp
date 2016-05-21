#include "..\Headers\Snake.hpp"

bool Snake::MoveAhead()
{
	// Set the position of the last piece
	lastPiece = myBodyPosition[myBodyPosition.size() - 1];

	// Swap all pieces to the front
	for (int i = myBodyPosition.size(); i > 1; i--)
	{
		myBodyPosition[i - 1] = myBodyPosition[i - 2];
	}

	// Get the value of the direction
	int directionValue = (int)myDirection;

	// The direction of the snake is vertical (divisible by 2)
	Position snakeHeadPosition = myBodyPosition[0];
	
	// Set the new position of the snake head
	if (directionValue % 2 == 0)
		snakeHeadPosition.y += directionValue / 2;
	else
		snakeHeadPosition.x += directionValue;

	myBodyPosition[0] = snakeHeadPosition;

	return true;
}

void Snake::IncreaseSize()
{
	if (&lastPiece != NULL)
	{
		// Increase the size variable
		mySize++;

		// Add one more piece to the body
		myBodyPosition.push_back(lastPiece);
	}
}

void Snake::ChangeDirection(Direction direction)
{
	myDirection = direction;
}

Snake::Snake(vector<Position> position, Direction direction)
{
	// Set the size of the snake
	mySize = position.size();

	// Set the position of the snake
	myBodyPosition = position;

	// Set the direction of the snake
	myDirection = direction;
}

