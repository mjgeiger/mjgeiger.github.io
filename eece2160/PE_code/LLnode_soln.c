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

// Add integer to list and return list's starting address
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
	// Create pointer to start of list
	LLnode *n = list;
	
	// Loop to visit all nodes in list
	while (n != NULL) {
		// For current node:
		//   a. Check if data you want is in that node --> return address if so
		if (v == n->value) {
			return n;
		}
		
		//   b. Otherwise, move to the next node
		n = n->next;
	}
	
	// If data isn't found, return NULL
	return NULL;
}

// Delete node from list (if present)
// Return starting address of list when done
LLnode *delNode(LLnode *list, int v) {
	LLnode *prev = NULL;
	LLnode *cur = list;
	
	while (cur != NULL && v != cur->value) {
		prev = cur;
		cur = cur->next;
	}
	
	if (cur == NULL)		// No match--went through entire list
		return list;
	
	else {			// Match found (v == cur->value), so delete cur node
		
		if (cur == list)		// Match found in first node
								// Alternate condition: prev == NULL
			list = cur->next;
		
		else		// Match found outside of first node
			prev->next = cur->next;
		
		free(cur);
		return list;
	}
}

// Print contents of entire list
void printList(LLnode *list) {
	// Create pointer to start of list
	LLnode *n = list;
	
	if (n == NULL)
		printf("List is empty\n");

	else {
		// Loop to visit all nodes in list
		while (n != NULL) {
			printf("%d\n", n->value);
			n = n->next;
		}
	}
}

// Keep list sorted in ascending order 
//   and add integer; return pointer to
//   start of list
LLnode *addSortedNode(LLnode *list, int v) {
	LLnode *prev = NULL;
	LLnode *cur = list;
	LLnode *newNode;
	
	// Allocate space for new node; exit if error
	newNode = (LLnode *)malloc(sizeof(LLnode));
	if (newNode == NULL) {
		fprintf(stderr, "Error: could not allocate new node\n");
		freeList(list);
		exit(0);
	}
	
	newNode->value = v;		// Copy value to new node
	
	// Search for first node to follow new node
	while (cur != NULL && cur->value <= v) {
		prev = cur;
		cur = cur->next;
	}
	
	// Make new node point to whatever follows it
	newNode->next = cur;
	
	// Make node before new one point to it
	if (prev == NULL)		// New node is first
		list = newNode;
	else					// New node is after first node
		prev->next = newNode;
	
	return list;
}

// Find node in sorted list and return pointer
//   (or NULL if not found)
LLnode *findSortedNode(LLnode *list, int v) {
	// Create pointer to start of list
	LLnode *n = list;
	
	// Loop to visit all nodes in list
	while (n != NULL && n->value <= v) {
		// Check if data you want is in current node --> return address if so
		if (v == n->value) {
			return n;
		}
		
		// Otherwise, move to the next node
		n = n->next;
	}
	
	// If data isn't found, return NULL
	return NULL;
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