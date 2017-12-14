/*************************************************
   EECE.2160: ECE Application Programming
   UMass Lowell
   M. Geiger
   Main program for 10th programming assignment
   Doubly-linked lists

********DO NOT MODIFY THIS FILE ********

**************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DLList.h"				// User-defined header file

int main() {
	DLList myList = {NULL, NULL};	// Doubly-linked list used throughout program
									// Since list is empty, firstNode and lastNode are
									//    both initialized to NULL
	DLNode *temp;					// Pointer used to hold result of find functions
	char cmd[25];					// Input command
	double vA, vB;					// Input values
	int numF, numR;					// Number of iterations to find value going fwd/rev

	do {
		printf("\nEnter command:  ");
		scanf("%s", cmd);		// Read string from standard input
	
		// Add word to list
		if (strcmp(cmd, "add") == 0) {
			printf("Enter values to be added:  ");
			scanf("%lf %lf", &vA, &vB);
			addNode(&myList, vA, vB);
		}

		// Delete word from list
		else if (strcmp(cmd, "delete") == 0) {
			printf("Enter value to be deleted:  ");
			scanf("%lf", &vA);
			delNode(&myList, vA);
		}

		// Find word in list
		else if (strcmp(cmd, "find") == 0) {
			printf("Enter value to be found:  ");
			scanf("%lf", &vA);
			temp = findFWD(&myList, vA, &numF);
			temp = findREV(&myList, vA, &numR);
			if (temp == NULL)
				printf("%.2lf not found in list\n", vA);
			else {
				printf("%.2lf found in node: %.2lf %.2lf\n", vA, temp->val1, temp->val2);
				printf("Forward search: %d iterations\n", numF);
				printf("Reverse search: %d iterations\n", numR);
			}			
		}

		// Print contents of entire list
		else if (strcmp(cmd, "print") == 0) {
			printFWD(&myList);
			printREV(&myList);
		}

		// Invalid command
		else if (strcmp(cmd, "exit") != 0)
			printf("Invalid command %s\n", cmd);

	} while (strcmp(cmd, "exit") != 0);
	
	freeList(&myList);
	return 0;
}
