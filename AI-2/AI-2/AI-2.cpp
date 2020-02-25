// AI-2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "board.h"

int playerTurn();

int main(int argc, char** argv)
{
	// Create gameboard and make strings/needed ints
	board gameBoard;
	string gameType, ifName, ofName, nextP;
	int depth;
	
	if (argc != 5) // Impropper number of arguments
		printf("Four command-line arguments are needed:\n");
		printf("Usage: %s interactive [input_file] [computer-next/human-next] [depth]\n", argv[0]);
		printf("or:  %s one-move [input_file] [output_file] [depth]\n", argv[0]);
		return 0;
	// diverge for game type
	gameType = argv[1];
	if (gameType == "interactive") { // interactive
		ifName = argv[2];
		ofName = argv[2];
		nextP = argv[3];
		depth = stoi(argv[4]);
		gameBoard = board();
		state startingState = gameBoard.readfile(ifName);

		if (nextP == "human-next" || nextP == "computer-next")

		// Time to play the game
		while (!gameBoard.gameOver()) { // While it isn't over
			if (nextP == "human-next") {

			}

		}
	}
	else if (gameType == "one-move") { // one-move
		// TODO
		cout << "Not yet implementned\n";
		return -1;
	}
	else { // Not a valid game type
		return -2;
	}

}

int playerTurn() {
	return 0;
}