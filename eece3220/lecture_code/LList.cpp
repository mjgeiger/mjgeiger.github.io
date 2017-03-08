//
//  LList.cpp
//  ds_test
//
//  Created by Michael Geiger on 3/5/17.
//  Copyright © 2017 Michael Geiger. All rights reserved.
//
// Linked list implementation discussed in EECE.3220
//   on 3/8/17 and 3/10/17
// Current version shows work completed on 3/8

#include "LList.h"
#include <cassert>

using std::nothrow;	 	// For use with new operator

// Default constructor
LList::LList() : first(NULL)
{}

// Copy constructor--responsible for creating new list and copying over
LList::LList(LList &orig)
{}

// Destructor--traverses list and deletes each node
LList::~LList() {}

// Assignment operator
LList & LList::operator=(const LList &rhs) {}

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
	
	// Add new node in ... on Friday
}

// Remove node with matching value
void LList::remove(int v) {}
