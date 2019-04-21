// EECE.3220: Data Structures
// M. Geiger
// Instructor solution for "Game of War" assignment
// Card.h: Card class interface
// YOU DO NOT HAVE TO MODIFY THIS FILE

#include <iostream>	
using std::ostream;

class Card {
public:
	Card();							// Default constructor
	void setCard(char,char);		// Change both rank and suit
	void printCard(ostream &out);	// Output card
	int compare(const Card &c2);	// Compare calling object to card c2
									// Returns: 1 if calling obj is "greater" (higher rank)
									//			0 if cards are equal (equal rank)
									//			-1 if calling obj is "less" (lower rank)

private:
	char rank;		// Card rank
	char suit;		// Card suit
};