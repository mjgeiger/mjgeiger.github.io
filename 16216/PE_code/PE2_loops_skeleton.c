#include <stdio.h>

void main() {
	char cmd;		// Input command
	char junk;		// Used to clear line
	int n;			// Integer used in calculations
	int nVals;		// # values read

	while (1) {		// Loop repeats until user enters 'X' or 'x'

		/* Read input command and number to be used */
		do {
			printf("Enter command and integer: ");
			nVals = scanf("%c %d", &cmd, &n);

			if (nVals == 2)		// Correctly formatted input
				break;			/* We haven't spent a lot of time on 
									break statements in class yet, 
									but a break statement in a loop
									exits the loop immediately. In
									this case, the program exits as
									soon as it receives valid input. */

			// Otherwise, clear line
			printf("Incorrectly formatted input\n");
			do {
				scanf("%c", &junk);
			} while (junk != '\n');
		} while (1);

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