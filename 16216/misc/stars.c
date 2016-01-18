/* 
 * 16.216: ECE Application Programming
 * stars.c -- solution to practice problem dealing with loops
 * Students must use nested loops to produce various patterns
 *   with different numbers of stars
 */

#include <stdio.h>
int main() {
	int i, j;		// Loop variables
	int limit;		// Variable used with slightly trickier loops
		
	/* Pattern 1 --> 5 lines, 4 stars per line:
		****
		****
		****
		****
		****										
	*/
	printf("----------------------------- Pattern 1\n");
	for (i = 0; i < 5; i++) {		// Outer loop produces 5 lines
		for (j = 0; j < 4; j++) {	// Inner loop produces 4 stars per line
			printf("*");
		}
		printf("\n");				// Newline at end of each line
	}


	/* Pattern 2 --> Number of stars per line starts at 1,
	   ends at 7, increments by 2 each time:
		*
		***
		*****
		*******
	*/
	printf("----------------------------- Pattern 2\n");
	for (i = 1; i <= 7; i += 2) {		// Outer loop produces four lines
										// Also specifies number of stars
										//   to be printed in each line
		for (j = 0; j < i; j++) {
			printf("*");
		}
		printf("\n");				// Newline at end of each line		
	}

	/* Pattern 3 --> Number of stars per line starts at 5
	   and decreases by 1 each time; last line has one star:
		*****
		****
		***
		**
		*
	*/
	printf("----------------------------- Pattern 3\n");
	for (i = 5; i >= 1; i--) {			// Outer loop produces five lines
										// Also specifies number of stars
										//   to be printed in each line
		for (j = 0; j < i; j++) {
			printf("*");
		}
		printf("\n");				// Newline at end of each line		
	}

	/* Pattern 4 --> Number of stars per line starts at 1, ends 
	   at 7, increments by 1 each time:
		*
		**
		***
		****
		*****
		******
		*******
	*/
	printf("----------------------------- Pattern 4\n");
	for (i = 1; i < 8; i++) {			// Outer loop produces seven lines
										// Also specifies number of stars
										//   to be printed in each line
		for (j = 0; j < i; j++) {
			printf("*");
		}
		printf("\n");				// Newline at end of each line		
	}

	/* Pattern 5 --> 7 lines, 9 stars per line:
		*********
		*********
		*********
		*********
		*********
		*********
		*********
	*/	
	printf("----------------------------- Pattern 5\n");
	for (i = 0; i < 7; i++) {		// Outer loop produces 7 lines
		for (j = 0; j < 9; j++) {	// Inner loop produces 9 stars per line
			printf("*");
		}
		printf("\n");				// Newline at end of each line
	}

	/* Pattern 6 --> Number of stars per line starts at 5,
	   ends at 13, increments by 2 each time:
		*****
		*******
		*********
		***********
		*************
	*/
	printf("----------------------------- Pattern 6\n");
	for (i = 5; i <= 13; i += 2) {		// Outer loop produces five lines
										// Also specifies number of stars
										//   to be printed in each line
		for (j = 0; j < i; j++) {
			printf("*");
		}
		printf("\n");				// Newline at end of each line		
	}

	/* Pattern 7 --> Number of stars goes from 7 to 3, decrementing
	   by 1, and back to 7:
		*******
		******
		*****
		****
		***
		****
		*****
		******
		*******
	*/
	printf("----------------------------- Pattern 7\n");
	for (i = -4; i <= 4; i++) {			// Outer loop produces nine lines
										// Also helps specify number of stars
										//   to be printed in each line
 
		if (i < 0)						// # stars = limit
			limit = (-i) + 3;			//		   = (absolute value of i) + 3
		else
			limit = i + 3;

		for (j = 0; j < limit; j++) {
			printf("*");
		}
		printf("\n");				// Newline at end of each line		
	}	

	/* Pattern 8 --> 5 lines; number of stars per line is always
	   i^2. Number starts at 25 (5*5) and ends at 1 (1*1)
		*************************
		****************
		*********
		****
		*
	*/
	printf("----------------------------- Pattern 8\n");
	for (i = 5; i > 0; i--) {			// Outer loop produces five lines
										// Also helps specify number of stars
										//   to be printed in each line
		for (j = 0; j < (i * i); j++) {	// Inner loop prints i*i stars per line
			printf("*");
		}
		printf("\n");				// Newline at end of each line		
	}	

	/* Pattern 9 --> 9 lines; 
	   First line has 26 - 1 = 25 stars
	   Next line has 26 - 4 = 22 stars
	   ...
	   Middle line has 26 - 25 = 1 star
	   Next line has 26 - 16 = 9 stars
	   ...
	   Last line has 26 - 1 = 25 stars

	   If i runs from -4 to 4 (to get 9 lines, which go from long to short 
	     and then back to long), then:
	   (# stars) = 26 - (5 - (absolute value of i))^2
	
		*************************
		**********************
		*****************
		**********
		*
		**********
		*****************
		**********************
		*************************
	*/
	printf("----------------------------- Pattern 9\n");
	for (i = -4; i <= 4; i++) {			// Outer loop produces nine lines
										// Also helps specify number of stars
										//   to be printed in each line
 
		// Use "limit" to hold absolute value of i, then overwrite with # stars
		if (i < 0)						
			limit = (-i);			
		else
			limit = i;
		limit = 26 - ((5 - limit) * (5 - limit));
		
		for (j = 0; j < limit; j++) {
			printf("*");
		}
		printf("\n");				// Newline at end of each line		
	}	

	/* Pattern 10 --> 11 lines; 
	   line length goes: 1, 3, ... 9, 11, 9 ... 3, 1
	   To get 9 lines, where width changes by 2 every time,
	   start i = -10, end at i == 10, and add 2 every time
	   # of stars then becomes 11 - (absolute value of i):
		*
		***
		*****
		*******	
		*********
		***********
		*********
		*******
		*****
		***
		*
	*/
	printf("----------------------------- Pattern 10\n");
	for (i = -10; i <= 10; i += 2) {	// Outer loop produces nine lines
										// Also helps specify number of stars
										//   to be printed in each line
 
		// limit == # stars == 11 - (absolute value of i)
		if (i < 0)						
			limit = 11 - (-i);			
		else
			limit = 11 - i;
		
		for (j = 0; j < limit; j++) {
			printf("*");
		}
		printf("\n");				// Newline at end of each line		
	}	

	return 0;
}
