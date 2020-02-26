// AI-2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "board.h"
#include "computer.h"

int getMove();
state swapState(state);

int main(int argc, char** argv)
{
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
//	cout << "'" << ifName << "'\n";
	currentState = gameBoard.readfile(ifName);
	if (gameType == "interactive") { // interactive
		ofName = argv[2];
		nextP = argv[3];
		depth = stoi(argv[4]);
		

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

				while (!gameBoard.addPiece(comp.nextMove(), currentState));// TODO get computer move

				nextP = "human-next"; // Set next player to human
				currentState = swapState(currentState);
			}
		}
		// gameBoard.writefile(ofName, currentState);
	}
	else if (gameType == "one-move") { // one-move
		// TODO
		cout << "Not yet Implemened\n";
		return -1;
	}
	else { // Not a valid game type
		cout << "Not a valid game type, Please enter \"interactive\"  or \"one-move\"\n\n";
		return -2;
	}

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