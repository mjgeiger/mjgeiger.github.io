/*
 * 16.216: ECE Application Programming, University of Massachusetts Lowell
 * Instructor: Dr. Michael Geiger
 *
 * 11/28/11: Programming Exercise 4
 * Program is intended to give students practice with string functions
 *
 * Complete examples from lecture; main program uses these functions
 */

#include <stdio.h>
#include <string.h>		// Included to allow use of string functions

// Function prototypes
int readStrings(char *s);					// Read strings until you find one that matches s
											// Return # strings read
void copyNull(char *s1, char *s2, int n);	// Copy first n characters of s2 into s1, and
											// ensure that s1 ends in NULL
int fillString(char *s, int n);				// Repeatedly read strings from standard input
											//   and concatenate to s until out of room
											// n = size of array s
											// Return final size of string

// Brief program to use functions above
int main() {
	char classNum[] = "16.216";			// Class number
	char inString[35];					// String to work with
	int n;

	// Read strings until something matches "16.216"
	// Print # of strings read
	n = readStrings(classNum);
	printf("%d strings read\n", n);

	// Copy classNum to inString
	copyNull(inString, classNum, 6);

	// Read strings repeatedly until inString is full
	// Concatenate results to inString
	n = fillString(inString, 35);
	printf("Final string: %s, string length: %d\n", inString, n);
}

// FUNCTION DEFINITIONS
/* Read strings until you find one that matches s
	Return # strings read */
int readStrings(char *s) {
	// INSERT CODE HERE
	return 0;
}

/* Copy first n characters of s2 into s1, and ensure that s1 ends in NULL */
void copyNull(char *s1, char *s2, int n) {
	// INSERT CODE HERE
}

/* Repeatedly read strings from standard input and concatenate to s until out of room
      n = size of array s
   Return final size of string */
int fillString(char *s, int n) {
	// INSERT CODE HERE
	return 0;
}