/* 
 * 16.216: ECE Application Programming
 * Instructor: M. Geiger
 * Source code for PE4 (Functions, pointers)
 * 3/30/2012
 */

#include <stdio.h>

/* Function prototype for change calculation */
void change(int *nCoins, int coinAmt, int *chgLeft);

void main() {
	double amt;			// Amount of change entered
	int nH, nQ, nD, nN;	// # of halves, quarters, dimes, nickels
	int nCents;			// Remaining change (in cents)

	printf("Enter amount of change: ");
	scanf("%lf", &amt);

	nCents = amt * 100;	// Convert change to integer # of cents

	// Calculate # of each coin type
	change(&nH, 50, &nCents);
	change(&nQ, 25, &nCents);
	change(&nD, 10, &nCents);
	change(&nN, 5, &nCents);

	printf("Original amount: $%.2lf\n", amt);
	printf("Change returned: %d half-dollars, %d quarters, %d dimes, %d nickels, %d pennies\n",
		nH, nQ, nD, nN, nCents);
}

// Change function
void change(int *nCoins, int coinAmt, int *chgLeft) {
	*nCoins = *chgLeft / coinAmt;
	*chgLeft = *chgLeft % coinAmt;
}