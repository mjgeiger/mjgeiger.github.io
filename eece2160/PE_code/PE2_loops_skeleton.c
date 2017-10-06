//
//  PE2_loops_skeleton.c
//  PE2_loops
//
//  Created by Michael Geiger on 10/6/17.
//  Copyright © 2017 Michael Geiger. All rights reserved.
//
//  Partial solution to second programming exercise

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main() {
	char cmd;		// Input command
	char junk;		// Used to clear line
	int n;			// Integer used in calculations
	int nVals;		// # values read

	while (1) {		// Loop repeats until user enters 'X' or 'x'

		/* Read input command and number to be used */
		do {
			printf("Enter command & n: ");
			nVals = scanf(" %c %d", &cmd, &n);
			if (nVals != 2) {
				printf("Formatting error\n");
				
				do {			// Clear line
					scanf("%c", &junk);
				} while (junk != '\n');
			}
		} while (nVals != 2);

		/* Evaluate cmd and perform appropriate operation */
		switch (cmd) {
		case 'F':
		case 'f':
			/* Calculate n! */
			printf("Will add code later to calculate n!\n");
			break;

		case 'P':
		case 'p':
			/* Calculate 2 to the nth power, if n >= 0; print error otherwise */
			printf("Will add code later to calculate 2 to the nth power\n"); 
			break;

		case 'X':
		case 'x':
			return;		// Exit program

		default:
			printf("Invalid command %c entered\n", cmd);
		}
	}	
}