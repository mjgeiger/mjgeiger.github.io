// EECE.3220: Data Structures
// M. Geiger
// Instructor solution for "Game of War" assignment
// Card.cpp: Card class implementation
// YOU DO NOT HAVE TO MODIFY THIS FILE

#include "Card.h"
using std::cout;

// Default constructor--creates "empty" card
Card::Card() : rank('-'), suit('-') {}

// Change both rank and suit
void Card::setCard(char r, char s) {
	rank = r;
	suit = s;
}

// Print card
void Card::printCard(ostream &out) {
	out << rank << suit;
}

// Compare calling object to card c2
// Returns: 1 if calling obj is "greater" (higher rank)
//			0 if cards are equal (equal rank)
//			-1 if calling obj is "less" (lower rank)
int Card::compare(const Card &c2) {

	// If ranks match, they're "equal"
	if (rank == c2.rank)
		return 0;

	// If rank is number, easy to compare
	else if (rank >= '2' && rank <= '9') {

		// Both numbers
		if (c2.rank >= '2' && c2.rank <= '9') {		
			if (rank > c2.rank) return 1;
			else				return -1;
		}

		// c2 = face card or 'T', so calling obj. must be "less"
		else					
			return -1;
	}

	// Calling obj is face card or 'T'
	else {
		if (c2.rank >= '2' && c2.rank <= '9')		// c2 = number
			return true;

		else {										// c2 = face card or 'T'

			// Go through possible choices for calling object, in rank order
			// Higher the rank, the fewer things it loses to
			//   Note: since every case returns a value, no need for breaks
			switch (rank) {
			case 'A':			// Ace always wins
				return 1;

			case 'K':			// King only loses to ace
				if (c2.rank == 'A')	
					return -1;
				else				
					return 1;

			case 'Q':			// Queen loses to A, K
				if (c2.rank == 'A' || c2.rank == 'K')	
					return -1;
				else									
					return 1;

			case 'J':			// Jack only beats T
				if (c2.rank == 'T')
					return 1;
				else
					return -1;

			case 'T':			// Ten beats no face cards
				return -1;

			default:
				cout << "Invalid rank!\n";
				return -1;
			}
		}
	}
}