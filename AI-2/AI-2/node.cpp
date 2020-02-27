#include <iostream>
#include<algorithm>
#include "node.h"
#include "board.h"

node::node(board& b)
{
	for (int i = 0; i < board::cols; i++) {
		for (int j = 0; j < board::rows; j++) {
			gamestate.pieces[i][j].color = b.pieces[i][j].color;
		}
	}
	for (int i = 0; i < board::cols; i++) {
		children[i] = NULL;
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

//returns the column to place in
int node::ABPrune(state color, int maxDepth) {
	if (gamestate.gameOver() || 0 >= maxDepth) {
		return -1;
	}
	// Set up ABpruneRec 
	int alpha = -10000000;
	int beta = 10000000;
	int value = -10000000;
	int column = -1;
	// We know we are max
	for (int i = 0; i < board::cols; i++) {
		if (addChildWithMove(i, color)) {
			state s;
			if (color == RED)
				s = GREEN;
			if (color == GREEN)
				s = RED;
			int j = children[i]->ABPruneRec(alpha, beta, s, 1, maxDepth, false);
			if (j > value) { // value = max(value, ab(child))
				value = j;
				column = i;
			}
			alpha = max(alpha, value); // alpha = max(alpha, value)
			if (alpha >= beta) { // beta cutoff
				break;
			}
		}
		else {
			children[i] = NULL;
		}
	}
	return column;
//	return ABPruneRec(-10000, 10000, color, 0, max_depth, true);
}



/* // Old ABPrune_not really how it works
int node::ABPrune(state color, int depth, int maxDepth) {
	MiniMax(color, depth, maxDepth);
	return prune(-10000, 10000, color, depth, maxDepth);
}*/

// Returns the pruned/final value of it's state 
int node::ABPruneRec(int alpha, int beta, state color, int depth, int maxDepth, bool maxOMin)
{
	// Base case - leaf node/max_depth
	if (gamestate.gameOver() || depth >= maxDepth) {
		for (int i = 0; i < board::cols; i++) {
			children[i] = NULL;
		}
//		gamestate.printBoard();
		return scoreH(color);
	}
	// min or max
	if (maxOMin) { // max node
		int value = -10000;
		for (int i = 0; i < board::cols; i++) {
			if (addChildWithMove(i, color)) {
				state s;
				if (color == RED)
					s = GREEN;
				if (color == GREEN)
					s = RED;
				int j = children[i]->ABPruneRec(alpha, beta, s, depth + 1, maxDepth, !maxOMin);
				value = max(j, value);
				alpha = max(alpha, value);
				if (alpha >= beta) { // beta cutoff
					break;
				}
			}
			else {
				children[i] = NULL;
			}
		}
		return value;
	}
	else {	// min node
		int value = 10000;
		for (int i = 0; i < board::cols; i++) {
			if (addChildWithMove(i, color)) {
				state s;
					if (color == RED)
						s = GREEN;
					if (color == GREEN)
						s = RED;
				int j = children[i]->ABPruneRec(alpha, beta, s, depth + 1, maxDepth, !maxOMin);
				value = min(j, value);
				beta = min(value, beta);
				if (alpha >= beta) { // alpha cutoff
					break;
				}
			}
			else {
				children[i] = NULL;
			}
		}
		return value;
	}
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

int node::scoreH(state color)
{
	int selfScore = gamestate.getScore(color);
	int enemyScore = 10000;
	if (color == RED)
		enemyScore = gamestate.getScore(GREEN);
	if (color == GREEN)
		enemyScore = gamestate.getScore(RED);
	return 2 * selfScore - enemyScore;
}

int node::max(int i , int j)
{
	if (i > j)
		return i;
	return j;	
}

int node::min(int i, int j)
{
	if (i < j)
		return i;
	return j;
}
