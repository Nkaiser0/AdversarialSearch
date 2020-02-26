#include "board.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

board::board()
{
}

bool board::addPiece(int column, state color)
{
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

bool board::gameOver()
{
	for (int i = 0; i < cols; i++) {
		if (canMove(i))
			return false;
	}
	return true;
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
	for (int i = 0; i < cols; i++)
		cout << "|" << i + 1;
	cout << "|\nScore: \033[31m" << getScore(RED) << "\033[0m - \033[32m" << getScore(GREEN) << "\033[0m\n";
	cout << "Moves so far: " << getMoveCount() << "\n\n";
}

state board::readfile(string fileName)
{
	ifstream file;
	file.open(fileName);
	vector<string> lines;
	string line;
	bool valid = true;
	int lineNum = 0;
	while (valid && getline(file, line)) {
		lineNum++;
		if (line.size() != 7 || (line.size() != 1 && lineNum != 7)) {
			valid = false;
		}
		for (int i = 0; i < line.size(); i++) {
			if (line[i] != 1 || line[i] != 2 || (line[i] != 0 && lineNum != 7)) {
				valid = false;
			}
		}
		lines.push_back(line);
	}
	if (line.size() != 7 || !valid) {
		return RED;
	}
	else {
		for (int i = lines.size() - 2; i >= 0; i--) {
			for (int j = 0; j < lines[i].size(); j++) {
				string temp = "" + lines[i][j];
				int current = stoi(temp);
				if (current == 1) {
					addPiece(j, RED);
				}
				else if (current == 2) {
					addPiece(j, GREEN);
				}
			}
		}
		if (stoi(lines[6]) == 1) {
			return RED;
		}
		else if (stoi(lines[6]) == 2) {
			return GREEN;
		}
	}
	return EMPTY;
}

bool board::writefile(string s, state next)
{
	ofstream write;
	write.open(s);
	
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

int board::getMoveCount()
{
	int count = 0;
	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < rows; j++) {
			if (pieces[i][j].color != EMPTY) // If not empty add to count
				count++;
			else // If empty then column is done
				break;
		}
	}
	return count;
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

