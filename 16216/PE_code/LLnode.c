/*************************************************
   16.216: ECE Application Programming
   UMass Lowell
   M. Geiger
   Source file for PE6: Dynamic memory allocation
   and data structures

   Contains function definitions for functions
   prototyped in LLnode.h
**************************************************/

#include <stdlib.h>
#include <stdio.h>
#include "LLnode.h"

LLnode *addNode(LLnode *list, int v) {
	LLnode *newNode;

	// Allocate space for new node; exit if error
	newNode = (LLnode *)malloc(sizeof(LLnode));
	if (newNode == NULL) {
		fprintf(stderr, "Error: could not allocate new node\n");
		exit(0);
	}

	newNode->value = v;		// Copy value to new node
	newNode->next = list;	// next points to old beginning of list
	return newNode;
}

// Find node in list and return pointer
//   (or NULL if not found)
LLnode *findNode(LLnode *list, int v) {
	printf("findNode() does nothing!\n");
	return NULL;
}

// Delete node from list (if present)
LLnode *delNode(LLnode *list, int v) {
	printf("delNode() does nothing!\n");
	return NULL;
}

// Print contents of entire list
void printList(LLnode *list) {
	printf("printList() does nothing!\n");
}

// Keep list sorted in ascending order 
//   and add integer; return pointer to
//   start of list
LLnode *addSortedNode(LLnode *list, int v) {
	printf("addSortedNode() does nothing!\n");
	return NULL;
}

// Find node in sorted list and return pointer
//   (or NULL if not found)
LLnode *findSortedNode(LLnode *list, int v) {
	printf("findSortedNode() does nothing!\n");
	return NULL;
}