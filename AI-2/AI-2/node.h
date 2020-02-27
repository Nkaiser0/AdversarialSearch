#include "board.h"
#pragma once
class node {

public:
	node(board& b);
	
	
	int score = 0;

	board gamestate;
	node* children[board::cols];

	bool addChildWithMove(int col, state color);
	
	int ABPrune(state color, int depth, int maxDepth);
	~node();
private:
	int MiniMax(state color, int depth, int maxDepth);
	int prune(int alpha, int beta, state color, int depth, int maxDepth);
	
};