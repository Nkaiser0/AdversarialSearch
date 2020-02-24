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


void board::printBoard()
{
	//prints from left to right, up to down
	cout << "Last Move: ";
	// TODO last move
	if (getLastMove() == GREEN)
		cout << " \033[32mgreen\033[0m";
	else
		cout << " \033[31mred\033[0m";
	cout << "\n";
	for (int i= rows-1; i>=0; i--) {
		for (int j = 0; j < cols; j++) {
			cout << "|";
			pieces[j][i].print();
		}
		cout << "|\n";
	}

	cout << "Score: \033[31m" << getScore(RED) << "\033[0m - \033[32m" << getScore(GREEN) << "\033[0m\n";
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

state board::getLastMove()
{
	int redCount(0), greenCount(0);
	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < rows; j++) {
			if (pieces[i][j].color == RED)
				redCount++;
			if (pieces[i][j].color == GREEN)
				greenCount++;
		}
	}
	if (redCount <= greenCount)
		return GREEN;
	return RED;
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

