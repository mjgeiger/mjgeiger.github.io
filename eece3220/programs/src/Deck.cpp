//
//  Deck.cpp
//  ds_test
//
//  Created by Michael Geiger on 4/17/17.
//  Copyright © 2017 Michael Geiger. All rights reserved.
//
//  Deck class for EECE.3220 Program 5

#include "Deck.h"

// Default constructor (empty deck)
// REWRITE AS APPROPRIATE FOR YOUR SOLUTION
Deck::Deck()
{}

// Returns true if deck is empty
bool Deck::empty() {

	// REPLACE LINE BELOW WITH YOUR SOLUTION
	return true;

}

// Deal top card (dequeue)
Card Deck::deal() {
	Card c;

	// ADD CODE TO ACTUALLY SET 
	//  c = "TOP" (FRONT) CARD FROM DECK
	//  AND DEQUEUE THAT CARD BEFORE
	//  RETURNING

	return c;
}

// Adds card c to bottom of deck
//  (basically an enqueue function)
void Deck::add(Card c) {
	// ADD YOUR SOLUTION HERE
}

// Reset and shuffle deck
// DO NOT CHANGE THIS FUNCTION UNLESS YOU
//   CHANGE YOUR Deck IMPLEMENTATION
void Deck::fill() {
	int positions[52];	// Array of card positions
	Card tempDeck[52];	// Temporary deck of cards
	int i, n;

	// First, fill temporary deck array
	char cRank[]={'2','3','4','5','6','7','8','9','T','J','Q','K','A'};
	char cSuit[]={ 'c', 'd', 'h', 's' };
	for (i = 0; i < 52; i++) {
		Card c;
		c.setCard(cRank[i % 13], cSuit[i / 13]);
		tempDeck[i] = c;
	}
	
	// Initialize position array to indicate
	//    unused positions
	for (i = 0; i < 52; i++)
		positions[i] = -1;
	
	// Choose 52 unique random numbers, which
	//    correspond to the new card positions
	i = 0;
	while (i < 52) {
		n = rand() % 52;
		if (positions[n] == -1) {
			positions[n] = i;
			i++;
		}
	}
	
	// Copy cards from temp deck to this deck
	for (i = 0; i < 52; i++) {
		(*this).add(tempDeck[positions[i]]);
	}
}

// Returns number of cards in deck
unsigned Deck::nCards() {

	// REPLACE THE LINE BELOW WITH YOUR SOLUTION
	return 0;
}