// AI-2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "board.h"


int main()
{
	board gameBoard = board();

	gameBoard.addPiece(1, RED);
	gameBoard.addPiece(2, RED);
	gameBoard.addPiece(2, RED);
	gameBoard.addPiece(3, RED);
	gameBoard.addPiece(3, RED);
	gameBoard.addPiece(3, RED);
	gameBoard.addPiece(4, RED);
	gameBoard.addPiece(4, RED);
	gameBoard.addPiece(4, RED);
	gameBoard.addPiece(4, RED);
	gameBoard.printBoard();

	cout << gameBoard.getScore(RED);

}