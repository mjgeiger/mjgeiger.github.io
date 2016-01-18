#include <stdio.h>

void main() {
	char cmd;		// Input command
	char junk;		// Used to clear line
	int n;			// Integer used in calculations
	int nVals;		// # values read
	int result;		// Result of operations
	int i;			// Loop index

	while (1) {		// Loop repeats until user enters 'X' or 'x'

		/* Read input command and number to be used */
		do {
			printf("Enter command and integer: ");
			nVals = scanf(" %c %d", &cmd, &n);

			if (nVals == 2)		// Correctly formatted input
				break;

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
			result = 1;
			for (i = n; i > 1; i--) {
				result *= i;
			}
			printf("%d! = %d\n", n, result);
			break;

		case 'P':
		case 'p':
			/* Calculate 2^n, if n >= 0; print error otherwise */
			if (n < 0)
				printf("Error: invalid value for n\n");

			else {
				result = 1;
				for (i = 0; i < n; i++) {
					result *= 2;
				}
				printf("2^%d = %d\n", n, result);
			}
			break;

		case 'X':
		case 'x':
			return;		// Exit program

		default:
			printf("Invalid command %c entered\n", cmd);
		}
	}	
}