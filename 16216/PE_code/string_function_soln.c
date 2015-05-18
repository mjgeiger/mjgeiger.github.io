/*
 * 16.216: ECE Application Programming, University of Massachusetts Lowell
 * Instructor: Dr. Michael Geiger
 *
 * 11/28/11: Programming Exercise 5
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
	char str[50];		// Input string
	int i = 0;			// # strings read in already

	// Repeatedly read string into str
	// Exit loop when s == str
	// Increment counter for every string read in
	do {
		scanf("%s", str);
		i++;
	} while (strcmp(s, str) != 0);

	return i;
}

/* Copy first n characters of s2 into s1, and ensure that s1 ends in NULL */
void copyNull(char *s1, char *s2, int n) {
	strncpy(s1, s2, n);
	s1[n] = '\0';
}

/* Repeatedly read strings from standard input and concatenate to s until out of room
      n = size of array s
   Return final size of string */
int fillString(char *s, int n) {
	char input[50];	// Assume max
						//   50 chars
	int charsLeft;	// Space remaining
						//   in s

	do {
		scanf("%s", input);
		
		// Calculate # chars left in array if input
		//   string is added. Need to leave room for ‘\0’
		charsLeft = n - (strlen(s) + 1) - strlen(input);

		if (charsLeft > 0)		// Enough space to add this string
			strcat(s, input);		//   and continue

		else {				// Out of room
			if (charsLeft == 0)	// Can add input, but then out of room
				strcat(s, input);	
			return strlen(s);
		}
	} while (1);
}
