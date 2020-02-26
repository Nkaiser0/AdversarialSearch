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
