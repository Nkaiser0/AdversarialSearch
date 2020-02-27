#include <time.h>
#include <stdlib.h>
#include "computer.h"

computer::computer()
{
	srand(time(NULL));
}

int computer::nextMove()
{
	return rand()%7;
}
