/*************************************************
   16.216: ECE Application Programming
   UMass Lowell
   M. Geiger
   Source file for PE6: Dynamic memory allocation
   and data structures

   Contains function definitions for functions
   prototyped in LLnode.h

   INSTRUCTOR SOLUTION
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
		freeList(list);
		exit(0);
	}

	newNode->value = v;		// Copy value to new node
	newNode->next = list;	// next points to old beginning of list
	return newNode;
}

// Find node in list and return pointer
//   (or NULL if not found)
LLnode *findNode(LLnode *list, int v) {
	LLnode *n;

	n = list;		// Start with first node

	while (n != NULL) {			// Search until after last node
		if (n->value == v)		// Data found--return n
			return n;
		n = n->next;
	}
	return NULL;				// If you get here, data wasn't found
}

// Delete node from list (if present)
LLnode *delNode(LLnode *list, int v) {
	LLnode *cur = list;		// Pointer to current node--initially start of list
	LLnode *prev = NULL;	// Pointer to node before cur--initially NULL

	// Loop will search list, stopping either 
	//   when list ends or value is found
	while ((cur != NULL) && (cur->value != v)) {
		prev = cur;
		cur = cur->next;
	}
	
	// Data wasn't found--return unmodified list
	if (cur == NULL)
		return list;

	// Data is in first node--must change pointer to start of list
	if (prev == NULL)
		list = list->next;

	// Data is in some other node
	// Set next pointer in prev (node before one being
	//   removed) to point past node being removed
	else
		prev->next = cur->next;

	free(cur);
	return list;
}

// Print contents of entire list
void printList(LLnode *list) {
	LLnode *n = list;

	while (n != NULL) {
		printf("%d\n", n->value);
		n = n->next;
	}
}

// Keep list sorted in ascending order 
//   and add integer; return pointer to
//   start of list
LLnode *addSortedNode(LLnode *list, int v) {
	LLnode *newNode;
	LLnode *cur = list; 
	LLnode *prev = NULL;

	// Allocate space for new node; exit if error
	newNode = (LLnode *)malloc(sizeof(LLnode));
	if (newNode == NULL) {
		fprintf(stderr, "Error: could not allocate new node\n");
		exit(0);
	}

	newNode->value = v;		// Copy value to new node

	// Search list to find right spot
	// When done, prev will point to spot before new 
	//   node, and cur will point to spot after it
	while ((cur != NULL) && (cur->value < v)) {
		prev = cur;
		cur = cur->next;
	}
	
	// Special case: new node goes at start of list
	if (prev == NULL) {
		newNode->next = cur;
		list = newNode;
	}

	// Otherwise, node goes somewhere in middle
	else {
		prev->next = newNode;
		newNode->next = cur;
	}
	return list;
}

// Find node in sorted list and return pointer
//   (or NULL if not found)
LLnode *findSortedNode(LLnode *list, int v) {
	LLnode *n;

	n = list;		// Start with first node

	// Search until after last node, or point at 
	//  which v can't possibly be in list
	while ((n != NULL) && (n->value <= v)) {	
		if (n->value == v)		// Data found--return n
			return n;
		n = n->next;
	}
	return NULL;				// If you get here, data wasn't found
}

// Frees entire list before end of program to avoid memory leaks
void freeList(LLnode *list) {
	LLnode *prev = NULL;	// "Previous" node
	LLnode *curr = list;	// "Current" node
	
	prev = NULL;
	curr = list;
	
	// If current node exists, remove it
	while (curr != NULL) {
		prev = curr;
		curr = curr->next;
		free(prev);
	}
}