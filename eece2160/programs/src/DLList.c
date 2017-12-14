/*************************************************
 EECE.2160: ECE Application Programming
 UMass Lowell
 M. Geiger
 Source file for 10th programming assignment
 Contains function definitions
 
	**********************************************
	STUDENTS MUST WRITE CODE TO CORRECTLY COMPLETE
	EACH FUNCTION DEFINITION BELOW, BUT SHOULD NOT
	MODIFY THE RETURN TYPE, NAME, OR ARGUMENTS OF
	ANY FUNCTION
	**********************************************

 **************************************************/

#include <stdlib.h>
#include <stdio.h>
#include "DLList.h"

// Find node containing v, searching from 1st node
// Return pointer to node, or NULL if nothing found
// Argument num points to number of iterations
DLNode *findFWD(DLList *list, double v, int *num) {
	
	/**** EECE.2160 PROGRAM 10 ****/
	/**** MUST TAKE OUT CODE BELOW AND CORRECTLY COMPLETE FUNCTION ****/
	printf("findFWD() doesn't do anything yet!\n");
	return NULL;
}

// Find node containing v, searching from last node
// Return pointer to node, or NULL if nothing found
// Argument num points to number of iterations
DLNode *findREV(DLList *list, double v, int *num) {
	
	/**** EECE.2160 PROGRAM 10 ****/
	/**** MUST TAKE OUT CODE BELOW AND CORRECTLY COMPLETE FUNCTION ****/
	printf("findREV() doesn't do anything yet!\n");
	return NULL;
}

// Add new node to list containing word
void addNode(DLList *list, double v1, double v2) {

	/**** EECE.2160 PROGRAM 10 ****/
	/**** MUST TAKE OUT CODE BELOW AND CORRECTLY COMPLETE FUNCTION ****/
	printf("addNode() doesn't do anything yet!\n");
}

// Delete node containing word from list
void delNode(DLList *list, double v) {

	/**** EECE.2160 PROGRAM 10 ****/
	/**** MUST TAKE OUT CODE BELOW AND CORRECTLY COMPLETE FUNCTION ****/
	printf("delNode() doesn't do anything yet!\n");
}

// Print contents of list, starting with 1st node
void printFWD(DLList *list) {

	/**** EECE.2160 PROGRAM 10 ****/
	/**** MUST TAKE OUT CODE BELOW AND CORRECTLY COMPLETE FUNCTION ****/
	printf("printFWD() doesn't do anything yet!\n");
}

// Print contents of list, starting with last node
void printREV(DLList *list) {

	/**** EECE.2160 PROGRAM 10 ****/
	/**** MUST TAKE OUT CODE BELOW AND CORRECTLY COMPLETE FUNCTION ****/
	printf("printREV() doesn't do anything yet!\n");
}

// Frees entire list before end of program to avoid memory leaks
// DO NOT MODIFY THIS FUNCTION
void freeList(DLList *list) {
	DLNode *prev = NULL;			// "Previous" node
	DLNode *curr = list->firstNode;	// "Current" node
	
	// If current node exists, remove it
	while (curr != NULL) {
		prev = curr;
		curr = curr->next;
		free(prev);
	}
}
