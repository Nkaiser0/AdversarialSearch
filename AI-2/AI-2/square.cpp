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
		std::cout << "\033[31mR\033[0m"; //\033[31mR\033[0m
		break;
	case GREEN:
		std::cout << "\033[32mG\033[0m"; //\033[32mG\033[0m
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
