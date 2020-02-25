#include "board.h"
#pragma once

class computer {

public:
	int maxDepth;
	computer(int depth);
	int getNextMove(board gameState);
};