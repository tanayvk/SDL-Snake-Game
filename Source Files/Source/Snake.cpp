#include "..\Headers\Snake.hpp"

bool Snake::MoveAhead()
{
	// Does the snake need to change its direction?
	if ( (float)((int)myDirection / myDirectionToMove) * (float)((int)myDirection / myDirectionToMove) != 1)
	{
		// Yes, change the direction
		myDirection = myDirectionToMove;
	}
	
	// Get the value of the direction
	int directionValue = (int)myDirection;

	// Set the position of the last piece
	lastPiece = myBodyPosition[myBodyPosition.size() - 1];

	// Swap all pieces to the front or back
	for (int i = myBodyPosition.size(); i > 1; i--)
	{
		myBodyPosition[i - 1] = myBodyPosition[i - 2];
	}

	// Set the new position of the snake head
	if (directionValue % 2 == 0)
		myBodyPosition[0].y += directionValue / 2;
	else
		myBodyPosition[0].x += directionValue;

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

		// Delete the last piece
		delete &lastPiece;
	}
}

void Snake::ChangeDirection(Direction direction)
{
	myDirectionToMove = direction;
}

bool Snake::IsOverlapping()
{
	for (int i = 1; i < mySize; i++)
	{
		if (myBodyPosition[0] == myBodyPosition[i])
			return true;
	}

	return false;
}

Snake::Snake(vector<Position> position, Direction direction)
{
	// Set the size of the snake
	mySize = position.size();

	// Set the position of the snake
	myBodyPosition = position;

	// Set the direction of the snake
	myDirectionToMove = myDirection = direction;
}

