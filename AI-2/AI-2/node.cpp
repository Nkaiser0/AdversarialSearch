#include "node.h"

node::node(board b)
{
	gameState = b;
}

node::~node()
{
	for (int i = 0; i < board::cols; i++) {
		children[i]->node::~node();
	}
	
}


int node::Search(state color)
{

}



void node::addChildWithMove(int col, state color)
{
	board newState = board(gameState);
	
	if (newState.canMove(col)) {
		newState.addPiece(col, color);
		children[col] = new node(newState);
	}
}

void node::populateTree(state color)
{
	for (int i = 0; i < board::cols; i++) {
		addChildWithMove(i, color);
		children[i]->populateTree(color == RED ? GREEN : RED);
	}

}
