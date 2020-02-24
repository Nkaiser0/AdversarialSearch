#pragma once
#include "square.cpp"
using namespace std;

class board {

public:
	const static int rows = 6;
	const static int cols = 7;
	square pieces[cols][rows];
	bool addPiece(int column, string color);
	void printBoard();
};