/*
 * EECE.3220: Data Structures
 * Instructor: M. Geiger
 * Linked stack definition
 *
 * Stack.cpp: function definitions
 */

#include "Stack.h"		// Implicitly includes <iostream>

// Constructor
Stack::Stack() : top(NULL)
{}

// Destructor
// Deletes nodes from stack until it's empty
Stack::~Stack()
{
	Node *temp;
	while (top != NULL) {
		temp = top;
		top = top->getNext();
		delete temp;
	}

	/** COULD HAVE WRITTEN AS:
	while (!empty()) {
		pop();
	}
	**/
}

// Checks if stack is empty
bool Stack::empty() const {
	return (top == NULL);
}

// Pushes data on top of stack
void Stack::push(const double &val) {
	top = new Node(val, top);
}

// Removes top item from stack
void Stack::pop() {
	Node *temp;
	if (top == NULL)
		cout << "Just kidding--stack is empty\n";
	else {
		temp = top;
		top = top->getNext();
		delete temp;
	}
}

double Stack::getTop() {
	return top->getVal();
}

void Stack::print(ostream &out) {
	Node *temp = top;
	while (temp != NULL) {
		cout << temp->getVal() << '\n';
		temp = temp->getNext();
	}
}

// Overloaded assignment--performs deep copy
Stack &Stack::operator =(const Stack &rhs) {
	/*** TO BE COMPLETED MONDAY 10/21 ***/
	return *this;
}

// Overloaded comparison
bool Stack::operator ==(const Stack &rhs) {
	Node *tmp1, *tmp2;	// Node pointer for each stack

	tmp1 = top;		// Top of calling object
	tmp2 = rhs.top;	// Top of RHS

	// Traverse stacks while:
	//  (1) Haven't hit end of either one (tested in loop condition), and
	//  (2) Data in all nodes so far match (if statement will exit if false)
	while (tmp1 != NULL && tmp2 != NULL) {

		// If mismatch found, exit loop
		if (tmp1->getVal() != tmp2->getVal())
			return false;

		// Move both Node pointers ahead to next node
		tmp1 = tmp1->getNext();
		tmp2 = tmp2->getNext();
	}

	// Stacks are same length & contain same data
	//   (if they were same length and contained different data,
	//    if statement in loop would have forced function to 
	//    return false before reaching this point)
	if (tmp1 == NULL && tmp2 == NULL)
		return true;
	
	// Else case: one stack is shorter than the other
	else
		return false;
}

// Overloaded output (non-friend function)
ostream &operator <<(ostream &out, Stack &aStack) {
	/*** TO BE COMPLETED MONDAY 10/21 ***/
	return out;
}

