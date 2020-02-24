#pragma once
#include "square.cpp"

class board {

public:
	const static int rows = 6;
	const static int cols = 7;
	square pieces[cols][rows];
	board();
	board(string);
	bool addPiece(int column);
	bool readfile(string);
	bool writefile(string);
};