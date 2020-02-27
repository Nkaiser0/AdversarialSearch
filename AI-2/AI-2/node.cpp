#include "node.h"
#include <iostream>
#include<algorithm>

node::node(board& b)
{
	for (int i = 0; i < board::cols; i++) {
		for (int j = 0; j < board::rows; j++) {
			gamestate.pieces[i][j].color = b.pieces[i][j].color;
		}
	}
}
node::~node() {
	for (int i = 0; i < board::cols; i++) {
		if (children[i] != NULL) {
			children[i]->~node();
			
		}
		free(children[i]);
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

int node::ABPrune(state color, int depth, int maxDepth) {
	MiniMax(color, depth, maxDepth);
	return prune(-10000, 10000, color, depth, maxDepth);
}

//returns the column number that it should move in next
int node::MiniMax(state color, int depth, int maxDepth)
{
	bool max = color == RED;
	
	score = gamestate.getScore(RED) - gamestate.getScore(GREEN);
	if (depth > maxDepth) {
		for (int i = 0; i < board::cols; i++) {
			children[i] = NULL;
		}
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

	/*int goalScore = max ? -100 : 100;
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

	return next;*/
	return 0;

}

int node::prune(int alpha, int beta, state color, int depth, int maxDepth)
{
	bool isMax = color == RED;

	if (depth < maxDepth) {
		for (int i = 0; i < board::cols; i++) {
			if (children[i] != NULL) {
				children[i]->prune(alpha, beta, color == RED ? GREEN : RED, depth + 1, maxDepth);
			}
			
		}
	}
	
	int next = -1;
	for (int i = 0; i < board::cols; i++) {
		if (children[i] != NULL) {
			if (isMax) {
				if (alpha < children[i]->score) {
					alpha = children[i]->score;
					next = i;
				}
				
			}
			else {
				if (beta > children[i]->score) {
					beta = children[i]->score;
					next = i;
				}
			}
		}
		if (alpha > beta) {
			score = alpha;
			return next;
		}
	}
	score = isMax ? alpha : beta;
	return next;
}
