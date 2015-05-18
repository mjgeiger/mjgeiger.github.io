/*
 * 16.216: ECE Application Programming, University of Massachusetts Lowell
 * Instructor: Dr. Michael Geiger
 *
 * 10/30/11: Programming Exercise 4
 * Program is intended to give students practice with functions, pointer arguments
 *
 * Given any amount of change under $2.00, determine and print minimum 
 *  number of coins required to make that change.
 * Assume available coins are: half dollars ($0.50 each), quarters ($0.25 each)
 *  dimes ($0.10 each), nickels ($0.05 each), and pennies ($0.01 each)
 */

#include <stdio.h>

/* FUNCTION PROTOTYPE--THIS PROGRAM SHOULD USE ONE FUNCTION, TO BE DEFINED
   DURING EXERCISE (SEE LECTURE NOTES IF YOU CAN'T MAKE CLASS) */
// Change function takes in following arguments:
//  nC    --> address of variable holding number of current coin type
//  vC    --> value of current coin type
//  myAmt --> address of variable holding total amount of remaining change
void change(int *nC, double vC, double *myAmt);

int main() {
	/* VARIABLE DECLARATIONS */
	double amount;				// Total amount of change to be returned
	int nH, nQ, nD, nN, nP;		// # of each type of coin

	/* ENTER AMOUNT OF CHANGE */
	printf("Enter amount of change: ");
	scanf("%lf", &amount);

	/* CALCULATE NUMBER OF EACH TYPE OF COIN TO BE USED */
	// Call change function, passing number of each coin type,
	//   value of each coin type, and total amount of change remaining
	change(&nH, 0.5, &amount);
	change(&nQ, 0.25, &amount);
	change(&nD, 0.1, &amount);
	change(&nN, 0.05, &amount);
	change(&nP, 0.01, &amount);
	
	/* PRINT FINAL RESULTS */
	printf("# half dollars: %d\n", nH);
	printf("# quarters: %d\n", nQ);
	printf("# dimes: %d\n", nD);
	printf("# nickels: %d\n", nN);
	printf("# pennies: %d\n", nP);

	return 0;
}

/* FUNCTION DEFINITION--SEE PROTOTYPE ABOVE */
// Change function takes in following arguments:
//  nC    --> address of variable holding number of current coin type
//  vC    --> value of current coin type
//  myAmt --> address of variable holding total amount of remaining change
//
// Calculates total number of coins with value vC that divide evenly into
//   change remaining, and updates variable holding remaining change
void change(int *nC, double vC, double *myAmt) {
	*nC = 0;

	/* In class, we used the following loop:

		while (*myAmt >= vC) {
			*myAmt = *myAmt - vC;
			*nC = *nC + 1;
		} 

		Remember that this function gave us a result that was always $.01 short,
			because floating point variables are often approximations. You therefore
			may run into trouble by checking if two floating point numbers
			are exactly equal to one another--in order to ensure the best results,
			only check floating point values for inequality (< or >).
		The code below shows a working solution that checks if (*myAmt < vC). */
	while (1) {
		// Exit loop if amount of remaining 
		//  change is less than value of coin
		if (*myAmt < vC)
			break;
		
		// Deduct amount of current coin and add 1 
		//  to the total number of this coin type
		*myAmt = *myAmt - vC;
		*nC = *nC + 1;
	}
}
