#include "board.h"

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

bool board::readfile(string)
{
	return false;
}

bool board::writefile(string)
{
	return false;
}