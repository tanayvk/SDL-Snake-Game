#include "..\Headers\Position.hpp"



Position::Position()
{
	x = 0;
	y = 0;
}

Position::Position(int argX, int argY)
{
	x = argX;
	y = argY;
}

bool Position::operator==(Position pos)
{
	if (x == pos.x && y == pos.y)
		return true;

	return false;
}
