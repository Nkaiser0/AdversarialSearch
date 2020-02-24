#include "board.h"
#include <iostream>

board::board()
{
}

board::board(string s)
{
	readfile(s);
}

bool board::addPiece(int column, string color)
{
	//column is indexed at one for user convenience, so minus one for use in array
	column--;

	for (int i = 0; i < rows; i++) {
		if (pieces[column][i].color == "") {
			pieces[column][i].color = color;
			return true;
		}
	}
	return false;
}


void board::printBoard()
{
	//prints from left to right, up to down
	for (int i= rows-1; i>=0; i--) {
		for (int j = 0; j < cols; j++) {
			cout << pieces[j][i].color << "\t";
		}
		cout << endl;
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

