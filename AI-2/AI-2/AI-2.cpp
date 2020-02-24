// AI-2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "board.h"


int main()
{
	board gameBoard = board();
	gameBoard.printBoard();

	gameBoard.addPiece(32, "");
	gameBoard.printBoard();

	gameBoard.addPiece(3, "red");
	gameBoard.printBoard();

}
