//
//  LList.hpp
//  ds_test
//
//  Created by Michael Geiger on 3/5/17.
//  Copyright © 2017 Michael Geiger. All rights reserved.
//
//  Linked list definition for EECE.3220

#ifndef LList_h
#define LList_h

#include <iostream>
using std::ostream;

class LList {
public:
	LList();								// Default constructor
	LList(LList &orig);						// Copy constructor
	~LList();								// Destructor
	LList & operator=(const LList &rhs);	// Assignment operator
	bool isEmpty();							// Returns true if list is empty
	void display(ostream &out);				// Print LList contents
	void insert(int v);						// Add new value to list
	void remove(int v);						// Remove node with matching value
private:
	class Node {
	public:
		int val;	// Value in each node
		Node *next;	// Pointer to next node
	};
	
	Node *first;	// Pointer to first node
};

#endif /* LList_h */
