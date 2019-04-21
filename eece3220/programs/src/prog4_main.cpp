//
//  prog5_main.cpp
//  ds_test
//
//  Created by Michael Geiger on 4/17/17.
//  Copyright © 2017 Michael Geiger. All rights reserved.
//

#include "Deck.h"		// <iostream> implicit
#include <cstdlib>		// Needed for rand(), srand()
using std::cout;
using std::cin;

int main() {
	unsigned seed;		// Random seed value
	Deck table;			// Represents cards on table, either
						//  at beginning of game or in the middle
						//  of each turn (before winner chosen)
	/*** ADD OTHER VARIABLE DECLARATIONS--PLAYER DECKS, ETC ***/
	
	// Prompt for and use random seed--no need to change these lines
	cout << "Enter seed: ";
	cin >> seed;
	srand(seed);
	
	// Reset and shuffle original deck
	table.fill();

	// Deal two equal piles from "table" into player decks
	/*** ADD CODE ***/
	
	// The main loop of the game
	while (/*** NEITHER PLAYER DECK IS EMPTY ***/) {

		/*** PRINT # CARDS IN EACH DECK, TOP CARD IN EACH DECK,
			 (WHICH I'D PLACE IN "table" AS IT'S DEALT FROM PLAYER DECK)
			 AND THEN DETERMINE WINNER FOR THAT TURN ***/

		/*** WINNING PLAYER GETS ALL CARDS FROM "table" ***/

		/*** IF THERE'S A TIE (WAR), DEAL 3 MORE CARDS FROM EACH PLAYER DECK
			 TO "table", THEN START A NEW TURN (THE 4TH CARD DEALT AFTER
			 THE TIE DETERMINES WHO WINS THE WAR, BUT YOU CAN TREAT THAT 
			 "4TH CARD" AS THE FIRST CARD OF A NEW TURN) ***/

	}

	/*** ONCE MAIN LOOP ENDS, ONE PLAYER DECK MUST BE EMPTY--OTHER PLAYER WINS! ***/

	return 0;
}