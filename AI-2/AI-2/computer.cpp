#include <time.h>
#include <stdlib.h>
#include "computer.h"

int computer::nextMove()
{
	return rand()%7;
}
