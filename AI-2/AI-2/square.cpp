#include <iostream>
#include "square.h"
using namespace std;
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
		cout << "\033[31mR\033[0m"; //\033[31mR\033[0m
		break;
	case GREEN:
		cout << "\033[32mG\033[0m"; //\033[32mG\033[0m
		break;
	case EMPTY:
	default:
		cout << " ";
	}
}
<<<<<<< HEAD

square& square::operator=(square& s)
{
	square temp = square(s.color);
	return temp;
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
=======
>>>>>>> 0f7dfbc395701f76bf5f36bb78092f7c3bf8870b
