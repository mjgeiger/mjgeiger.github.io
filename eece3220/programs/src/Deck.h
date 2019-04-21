// EECE.3220: Data Structures
// M. Geiger
// Instructor solution for "Game of War" assignment
// Deck.h: Card class interface

#ifndef Deck_h
#define Deck_h

#include "Card.h"

class Deck {
public:
	Deck();				// Default constructor (empty deck)
	bool empty();		// Returns true if deck is empty
	Card deal();		// Deal top card (dequeue & return)
	void add(Card c);	// Adds card c to bottom of deck (enqueue)
	void fill();		// Reset and shuffle deck
	unsigned nCards();	// Returns number of cards in deck
private:

	/* 
	   This list of data members assumes an array-based
		queue that does not track the number of cards in
		the deck at any point in time, and therefore requires
		one extra, empty spot in the array (which is why we
		have a 53-Card array when the max deck size is 52).
	   You may change the list of data members, but be sure
	    to then modify the fill() implementation I wrote for
		you to account for your changes--see me if you have
		questions
	*/
	Card myDeck[53];	// Queue of cards
	int top, bottom;	// Top and bottom positions in deck
						// (front and back of queue)
};

#endif /* Deck_h */
