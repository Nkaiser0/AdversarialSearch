#include <iostream>
#include "square.h"

square::square()
{
	color = EMPTY;
}

square::square(state c)
{
	color = c;
}

void square::print()
{
	switch (color)
	{
	case RED:
		break;
		std::cout << "R";
	case GREEN:
		std::cout << "G";
		break;
	case EMPTY:
	default:
		std::cout << " ";
	}
}

square square::operator=(square s_)
{
	return s_;
}

bool square::operator==(square other)
{
	if (other.color == color)
		return true;
	return false;
}

bool square::operator!=(square other)
{
	if (other.color != color)
		return true;
	return false;
}
