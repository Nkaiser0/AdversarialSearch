// AI-2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "board.h"
#include "computer.h"
#include "node.h"

int getMove();
state swapState(state);

int main(int argc, char** argv)
{
	board gameBoard = board();
	gameBoard.addPiece(0, GREEN);
	gameBoard.addPiece(0, GREEN);
	gameBoard.addPiece(0, GREEN);
	gameBoard.addPiece(2, RED);
	gameBoard.addPiece(4, RED);
	gameBoard.addPiece(5, RED);
	gameBoard.addPiece(6, RED);
	gameBoard.printBoard();
	
	node base = node(gameBoard);
	cout << base.MiniMax(GREEN, 1,5) << endl;
	/*
	// Create gameboard and make strings/needed ints
	board gameBoard = board();
	computer comp;
	state currentState;
	string gameType, ifName, ofName, nextP;
	int depth;
	if (argc != 5) { // Impropper number of arguments
		printf("Four command-line arguments are needed:\n");
		printf("Usage: %s interactive [input_file] [computer-next/human-next] [depth]\n", argv[0]);
		printf("or:  %s one-move [input_file] [output_file] [depth]\n", argv[0]);
		return 0;
	}
	// diverge for game type
	gameType = argv[1];
	ifName = argv[2];
	depth = stoi(argv[4]);
//	cout << "'" << ifName << "'\n";
	currentState = gameBoard.readfile(ifName);
	if (gameType == "interactive") { // interactive
		nextP = argv[3];

		if (nextP != "human-next" && nextP != "computer-next") { // If we don't have a valid next player
			cout << "Choose what type of player goes next \"human-next\" or \"computer-next\".\n\n";
			return -1;
		}
		// Time to play the game
		while (!gameBoard.gameOver()) { // While it isn't over
			gameBoard.printBoard();
			if (nextP == "human-next") { // If it is the player turn
				//
				while (!gameBoard.addPiece(getMove(), currentState)); // get and do a valid move

				nextP = "computer-next"; // set next player to the computer
				currentState = swapState(currentState);
			}
			else { // If it is the computer turn

				while (!gameBoard.addPiece(comp.nextMove(), currentState));// get computer move

				nextP = "human-next"; // Set next player to human
				currentState = swapState(currentState);
			}
		}
	}
	else if (gameType == "one-move") { // one-move
		ofName = argv[3];
		gameBoard.printBoard();
		if (gameBoard.gameOver()) {
			cout << "The game is already over.\n\n";
			return 0;
		}
		while (!gameBoard.addPiece(comp.nextMove(), currentState));// get computer move
		currentState = swapState(currentState);
		gameBoard.printBoard();
		gameBoard.writefile(ofName, currentState);
	}
	else { // Not a valid game type
		cout << "Not a valid game type, Please enter \"interactive\"  or \"one-move\"\n\n";
		return -2;
	}*/

	return 0;
}

int getMove() {
	cout << "Enter the column you would like to place your piece in: ";
	string str;
	getline(cin, str);
	return stoi(str) - 1;
}

state swapState(state s) {
	if (s == RED)
		return GREEN;
	if (s == GREEN)
		return RED;
	cout << "Invalid turn identity\n";
	return EMPTY;

}