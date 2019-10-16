//
//  LList.cpp
//  ds_test
//
//  Created by Michael Geiger on 3/5/17.
//  Copyright © 2017 Michael Geiger. All rights reserved.
//
// Linked list implementation discussed in EECE.3220
//   on 3/8/17 and 3/10/17
// Previous version showed work completed on 3/8
// Current version shows work completed on 3/10
//   + definition of assignment operator

#include "LList.h"
#include <cassert>

using std::nothrow;	 	// For use with new operator
using std::cout;

// Default constructor
LList::LList() : first(NULL)
{}

// Copy constructor--responsible for creating new list and copying over
LList::LList(LList &orig) : first(NULL)
{
	// The short version: *this = orig;
	
	// The long, drawn out version
	Node *newNode = NULL;	// Newly allocated node
	Node *pred;				// Predecessor of new node
	Node *origNode;			// Current node in original list
	
	// Go through every node in original list & create copy
	origNode = orig.first;
	while (origNode != NULL) {
		
		// Allocate new node
		newNode = new (nothrow) Node;
		assert(newNode != NULL);
		newNode->val = origNode->val;
		
		// Make predecessor point to new node
		if (origNode == orig.first)	// Adding new first node
			first = newNode;
		else
			pred->next = newNode;
		
		origNode = origNode->next;
		pred = newNode;
	}
	
	// Set next pointer for last node
	pred->next = NULL;   // or newNode->next = NULL;
}

// Destructor--traverses list and deletes each node
LList::~LList() {
	Node *cur, *nextNode;	// Pointer to current, next node

	// Delete list as long as it's not empty
	if (first != NULL) {
		cur = first;
		nextNode = first->next;
		
		while (nextNode != NULL) {
			delete cur;
			cur = nextNode;
			nextNode = nextNode->next;
		}
		
		// Delete last node
		delete cur;
	}
}

// Assignment operator
LList & LList::operator=(const LList &rhs) {
	Node *newNode = NULL;	// Newly allocated node
	Node *pred;				// Predecessor of new node
	Node *origNode;			// Current node in original list
	
	// Account for empty list on right hand side
	if (rhs.first == NULL)
		first = NULL;
	
	// Otherwise, go through every node in original list & create copy
	else {
		origNode = rhs.first;
		while (origNode != NULL) {
			
			// Allocate new node
			newNode = new (nothrow) Node;
			assert(newNode != NULL);
			newNode->val = origNode->val;
			
			if (origNode == rhs.first)	// Adding new first node
				first = newNode;
			else						// Adding new node later in list
				pred->next = newNode;

			pred = newNode;				// New node will be predecessor
										//   of next node added
			origNode = origNode->next;
		}
		
		// Set next pointer for last node
		pred->next = NULL;   // or newNode->next = NULL;
	}
	
	return *this;
}

// Returns true if list is empty
bool LList::isEmpty() {
	return (first == NULL);
}

// Print LList contents
void LList::display(ostream &out) {
	Node *ptr = first;
	
	// Check for empty list
	if (ptr == NULL)
		out << "Empty list";
	
	// Traverse all nodes and print contents
	while (ptr != NULL) {
		out << ptr->val << " ";
		ptr = ptr->next;
	}
	out << "\n";
}

// Add new value to list
void LList::insert(int v) {
	Node *newNode;		// Pointer to newly allocated node
	Node *prev;			// Predecessor of new node
	Node *cur;			// Current node
	
	// Allocate new node
	newNode = new (nothrow) Node;
	assert(newNode != NULL);
	newNode->val = v;
	
	// Find appropriate spot to place new node
	cur = first;
	prev = NULL;
	while (cur != NULL && cur->val < v) {
		prev = cur;
		cur = cur->next;
	}

	// Point new node to successor
	newNode->next = cur;
	
	// Point predecessor to new node
	if (prev == NULL)
		first = newNode;
	else
		prev->next = newNode;
}

// Remove node with matching value
void LList::remove(int v) {
	Node *prev;		// Predecessor of node to be deleted
	Node *cur;
	
	// Find node, if it's in list
	cur = first;
	prev = NULL;
	while (cur != NULL && cur->val < v) {
		prev = cur;
		cur = cur->next;
	}
	
	// Didn't find node
	if (cur == NULL || cur->val > v) {
		cout << "Node with value " << v << " not found\n";
		return;
	}
	
	// Otherwise, remove node
	if (prev == NULL)
		first = cur->next;
	else
		prev->next = cur->next;
	delete cur;
}
