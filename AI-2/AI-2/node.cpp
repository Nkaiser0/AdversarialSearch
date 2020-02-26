#include "node.h"
#include <iostream>

node::node(board& b)
{
	for (int i = 0; i < board::cols; i++) {
		for (int j = 0; j < board::rows; j++) {
			gamestate.pieces[i][j].color = b.pieces[i][j].color;
		}
	}
}

bool node::addChildWithMove(int col, state color)
{
	board newState = board(gamestate);

	if (newState.canMove(col)) {
		newState.addPiece(col, color);
		children[col] = new node(newState);
		return true;
	}
	return false;
}

//returns the column number that it should move in next
int node::MiniMax(state color, int depth, int maxDepth)
{
	bool max = color == RED;
	
	score = gamestate.getScore(RED) - gamestate.getScore(GREEN);
	if (depth > maxDepth) {
		return -1;
	}

	for (int i = 0; i < board::cols; i++) {
		if (addChildWithMove(i, color) ) {
			children[i]->MiniMax(color == RED ? GREEN : RED, depth+1, maxDepth);
		}
		else {
			children[i] = NULL;
		}
		
	}

	int goalScore = max ? -100 : 100;
	int next = -1;

	for (int i = 0; i < board::cols; i++) {
		if (children[i] != NULL) {
			if (max) {
				if (children[i]->score > goalScore) {
					goalScore = children[i]->score;
					next = i;
				}
			}
			else {
				if (children[i]->score < goalScore) {
					goalScore = children[i]->score;
					next = i;
				}
			}
		
		}
		
	}

	score = goalScore;

	return next;

}
