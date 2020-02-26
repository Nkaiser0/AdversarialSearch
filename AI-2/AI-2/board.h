#pragma once
#include "square.h"
using namespace std;

class board {

public:
	board();

	const static int rows = 6;
	const static int cols = 7;
	square pieces[cols][rows];

	bool addPiece(int column, state color);
	void printBoard();
	state readfile(string fileName);
	bool writefile(string, state);
	int getScore(state);
	int getMoveCount();
	bool canMove(int col);
	bool gameOver();

private:
	state getLastMove();
	bool hasVerticalScore(int col, int row, state color);
	bool hasRightDiagonalScore(int col, int row, state color);
	bool hasLeftDiagonalScore(int col, int row, state color);
	bool hasHorizontalScore(int col, int row, state color);
};