//
//  dice_example.c
//
//  Created by Michael Geiger on 10/6/17.
//  Copyright © 2017 Michael Geiger. All rights reserved.
//
//  Short example program to demonstrate use of rand() and srand(),
//    as well as input validation loops and line clearing

#define _CRT_SECURE_NO_WARNINGS		// Remove scanf() warning in VS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	unsigned d1, d2;	// Two dice
	unsigned match;		// Dice roll to match
	int n;				// Used to check for formatting errors
	char junk;			// Used for line clearing
	int seed;			// Seed for random number generator

	// Prompt for and read seed value for RNG
	do {
		printf("Enter seed (-1 to use system time): ");
		n = scanf("%d", &seed);
		if (n < 1) {		// Formatting error
			printf("Could not read input\n");
			
			do {			// Clear line
				scanf("%c", &junk);
			} while (junk != '\n');
		}
	} while (n < 0);
	
	// Seed RNG using current time or user input
	if (seed == -1)
		srand(time(0));
	else
		srand(seed);
	
	// Repeatedly prompt for and read value to
	//   match until there are no errors
	do {
		printf("Enter value between 2 and 12: ");
		n = scanf("%u", &match);
		
		if (n < 1) {		// Formatting error
			printf("Could not read input\n");
			
			do {			// Clear line
				scanf("%c", &junk);
			} while (junk != '\n');
		}
		
		else if (match < 2 || match > 12)		// Valid values for sum of
			printf("Invalid match value\n");	//   2 dice are between 2 & 12
		
	} while (n < 1 || match < 2 || match > 12);
	
	// Repeatedly "roll" dice until sum matches user input
	do {
		d1 = (rand() % 6) + 1;		// Produces value between 1 and
		d2 = (rand() % 6) + 1;		//   6 for each die
		printf("Roll: %u + %u = %u\n", d1, d2, d1 + d2);
	} while (match != d1 + d2);
	
	printf("Got a match!\n");
	
	return 0;
}
