/*
 * M. Geiger
 * EECE.3220: Data Structures
 *
 * Source file for in-class stack example
 * Stack member function definitions
 */

#include "Stack.h"

/* Data members:
	double *list;	// The actual data stored on the stack
	int tos;		// Index for top of stack
	unsigned cap;	// Capacity (max size) of stack
*/

// Constructor
Stack::Stack(unsigned maxSize = 1024) : 
	cap(maxSize), tos(-1)
{
	list = new double[cap];
}

// Destructor
Stack::~Stack() {
	delete[] list;
}

bool empty() const;					// Returns true if stack empty
void push(const double &val);		// Push val to top of stack
void pop();							// Remove top of stack
double top();						// Read c