/*************************************************
   16.216: ECE Application Programming
   UMass Lowell
   M. Geiger
   Main program for PE6: Dynamic memory allocation
   and data structures

   Works with singly linked list, which is defined
   in separate file
**************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LLnode.h"				// Contains LLNode definition, function prototypes

char *readLine();				// Reads string from input and dynamically allocates space

int main() {
	LLnode *first = NULL;			// Pointer to start of list
	LLnode *temp;
	char *cmd = NULL;				// Input command
	int inVal;						// Input value
	char sorted;					// Test to see if list should be sorted
	char junk;						// Used to hold newline

	// Ask user to determine if list should be sorted
	printf("Use sorted linked list? (Y/N)  ");
	scanf("%c%c", &sorted, &junk);
	
	do {
		printf("\nEnter command:  ");
		cmd = readLine();		// Read string from standard input
	
		// Add integer to list
		if (strcmp(cmd, "add") == 0) {
			printf("Enter number to be added:  ");
			scanf("%d%c", &inVal, &junk);

			// Choose between sorted/unsorted list functions
			if (sorted == 'Y')
				first = addSortedNode(first, inVal);
			else
				first = addNode(first, inVal);
		}

		// Delete word from list
		else if (strcmp(cmd, "delete") == 0) {
			printf("Enter number to be deleted:  ");
			scanf("%d%c", &inVal, &junk);
			first = delNode(first, inVal);
		}

		// Find word in list
		else if (strcmp(cmd, "find") == 0) {
			printf("Enter number to be found:  ");
			scanf("%d%c", &inVal, &junk);
			
			// Choose between sorted/unsorted list functions
			if (sorted == 'Y')
				temp = findSortedNode(first, inVal);
			else
				temp = findNode(first, inVal);

			if (temp == NULL)
				printf("%d not found in list\n", inVal);
			else
				printf("%d found in list\n", inVal);
		}

		// Print contents of entire list
		else if (strcmp(cmd, "print") == 0)
			printList(first);

		// Invalid command
		else if (strcmp(cmd, "exit") != 0)
			printf("Invalid command %s\n", cmd);

	} while (strcmp(cmd, "exit") != 0);

	freeList(first);		// Free list before exiting
	return 0;
}

// Reads string from standard input and dynamically allocates space
// Assumes string terminates with '\n'
char *readLine() {
	int i = 0;			// Loop index
	char *inStr;		// Input string
	char *tempStr;		// Temp string
	char inCh;			// Input character
	i = 0;

	inStr = (char *)malloc(1);	// Start with 1-character string
	if (inStr == NULL) {
		fprintf(stderr, "Could not allocate\n");
		return NULL;
	}

	// Repeatedly read input characters and reallocate space to store string
	while ((inCh = fgetc(stdin)) != '\n') {
		inStr[i++] = inCh;
		tempStr = (char *) realloc(inStr, (i + 1) * sizeof(char));
		
		// Reallocation failed
		if (tempStr == NULL) {
			fprintf(stderr, "Could not reallocate\n");
			return inStr;
		}

		// Reallocation successful; assign tempStr to inStr
		else inStr = tempStr;
	} 

	inStr[i] = '\0';
	return inStr;
}