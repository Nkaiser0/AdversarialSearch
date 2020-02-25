#include "board.h"
#pragma once
class node {
public:
	node(board);
	~node();

	board gameState;
	int bestImprovement = 0;
	node* children[board::cols];

	void addChildWithMove(int col, state color);
	void populateTree(state color);
	int Search(state color);
	void prune(state color)
};