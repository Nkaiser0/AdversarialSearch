// AI-2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdexcept>
#include "board.h"
#include "computer.h"
#include "node.h"

int getMove();
state swapState(state);

int main(int argc, char** argv)
{
	//TODO FIX THE BULLSHIT wehre the compter refuses to play in col 7 when nothing is in there yet
	/*board gameBoard = board();
	gameBoard.addPiece(0, RED);
	gameBoard.addPiece(1, RED);
	gameBoard.addPiece(2, RED);
	gameBoard.printBoard();
	node base = node(gameBoard);
	cout << base.ABPrune(RED, 1, 2) << endl;*/
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
//				while (!gameBoard.addPiece(getMove(), currentState)); // get and do a valid move
				while (!gameBoard.addPiece(comp.nextMove(), currentState)); // get and do a valid move
				nextP = "computer-next"; // set next player to the computer
				currentState = swapState(currentState);
			}
			else { // If it is the computer turn
				gameBoard.printBoard();
				node base = node(gameBoard);
				int nextCol = base.ABPrune(currentState, depth);
				if (nextCol == -1) {
					nextCol = gameBoard.getNextOpenCol();
				}
				gameBoard.addPiece(nextCol, currentState);// get computer move

				nextP = "human-next"; // Set next player to human
				currentState = swapState(currentState);
			}
		}
		gameBoard.printBoard();
	}
	else if (gameType == "one-move") { // one-move
		ofName = argv[3];
		gameBoard.printBoard();
		if (gameBoard.gameOver()) {
			cout << "The game is already over.\n\n";
			return 0;
		}
		node base = node(gameBoard);
		int nextCol = base.ABPrune(currentState, depth);
		if (nextCol == -1) {
			nextCol = gameBoard.getNextOpenCol();
		}
		gameBoard.addPiece(nextCol, currentState);// get computer move
		currentState = swapState(currentState);
		gameBoard.printBoard();
		gameBoard.writefile(ofName, currentState);
	}
	else { // Not a valid game type
		cout << "Not a valid game type, Please enter \"interactive\"  or \"one-move\"\n\n";
		return -2;
	}
	
	return 0;
}

int getMove() {
	cout << "Enter the column you would like to place your piece in: ";
	string str;
	int i;
	getline(cin, str);
	try {
		i = stoi(str);
	}
	catch (invalid_argument e) {
		return -1;
	}
	return i - 1;
}

state swapState(state s) {
	if (s == RED)
		return GREEN;
	if (s == GREEN)
		return RED;
	cout << "Invalid turn identity\n";
	return EMPTY;
}