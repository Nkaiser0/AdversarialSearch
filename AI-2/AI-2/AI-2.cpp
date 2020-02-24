// AI-2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "board.h"


int main()
{
	board gameBoard = board();

	gameBoard.addPiece(1, RED);
	gameBoard.printBoard();
	gameBoard.addPiece(2, GREEN);
	gameBoard.printBoard();
	gameBoard.addPiece(2, RED);
	gameBoard.printBoard();
	gameBoard.addPiece(3, GREEN);
	gameBoard.printBoard();
	gameBoard.addPiece(3, RED);
	gameBoard.printBoard();
	gameBoard.addPiece(3, GREEN);
	gameBoard.printBoard();
	gameBoard.addPiece(4, RED);
	gameBoard.printBoard();
	gameBoard.addPiece(4, GREEN);
	gameBoard.printBoard();
	gameBoard.addPiece(4, RED);
	gameBoard.printBoard();
	gameBoard.addPiece(4, GREEN);
	gameBoard.printBoard();

}