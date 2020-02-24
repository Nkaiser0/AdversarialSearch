#include "board.h"
#include <iostream>

board::board()
{
}

board::board(string s)
{
	readfile(s);
}

bool board::addPiece(int column, state color)
{
	//column is indexed at one for user convenience, so minus one for use in array
	column--;

	if (column >= cols) {
		return false;
	}

	for (int i = 0; i < rows; i++) {
		if (pieces[column][i].color == EMPTY) {
			pieces[column][i].color = color;
			return true;
		}
	}
	return false;
}

bool board::canMove(int col) {
	return pieces[col][rows - 1] == EMPTY;
}


void board::printBoard()
{
	//prints from left to right, up to down
	for (int i= rows-1; i>=0; i--) {
		cout << "[";
		for (int j = 0; j < cols; j++) {
			cout << "|";
			pieces[j][i].print();
		}
		cout << "|\n";
	}

}

bool board::readfile(string)
{
	return false;
}

bool board::writefile(string)
{
	return false;
}

int board::getScore(state color) {
	int score = 0;
	for (int i = rows - 1; i >= 0; i--) {
		for (int j = 0; j < cols; j++) {
			score += hasVerticalScore(j, i, color);
			score += hasRightDiagonalScore(j, i, color);
			score += hasLeftDiagonalScore(j, i, color);
			score += hasHorizontalScore(j, i, color);
		}
	}
	return score;
}

bool board::hasVerticalScore(int col, int row, state color) {
	//assume positions are 0 indexed
	if (row<=2) {
		return false;
	}
	
	return (pieces[col][row].color == color && 
		pieces[col][row-1].color == color &&
		pieces[col][row-2].color == color &&
		pieces[col][row-3].color == color );
}

bool board::hasRightDiagonalScore(int col, int row, state color) {
	//assume positions are 0 indexed
	if (row<=2 || col >=4) {
		return false;
	}

	return (pieces[col][row].color == color &&
		pieces[col+1][row - 1].color == color &&
		pieces[col+2][row - 2].color == color &&
		pieces[col+3][row - 3].color == color);
}

bool board::hasLeftDiagonalScore(int col, int row, state color) {
	//assume positions are 0 indexed
	if (row <= 2 || col <= 2) {
		return false;
	}

	return (pieces[col][row].color == color &&
		pieces[col - 1][row - 1].color == color &&
		pieces[col - 2][row - 2].color == color &&
		pieces[col - 3][row - 3].color == color);
}

bool board::hasHorizontalScore(int col, int row, state color) {
	//assume positions are 0 indexed
	if (col >= 4) {
		return false;
	}

	return (pieces[col][row].color == color &&
		pieces[col+1][row].color == color &&
		pieces[col+2][row].color == color &&
		pieces[col+3][row].color == color);
}

