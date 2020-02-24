#pragma once
#include "square.h"
using namespace std;

class board {

public:
	board();
	board(string);

	const static int rows = 6;
	const static int cols = 7;
	square pieces[cols][rows];

	bool addPiece(int column, state color);
	void printBoard();
	bool readfile(string);
	bool writefile(string);
	int getScore(state);
private:
	bool hasVerticalScore(int col, int row, state color);
	bool hasRightDiagonalScore(int col, int row, state color);
	bool hasLeftDiagonalScore(int col, int row, state color);
	bool hasHorizontalScore(int col, int row, state color);
};