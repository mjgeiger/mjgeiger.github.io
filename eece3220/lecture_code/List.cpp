//
//  List.cpp
//  ds_test
//
//  Created by Michael Geiger on 2/24/17.
//  Figure 6.1B from Nyhoff text
//

#include "List.h"
using namespace std;

//--- Definition of class constructor
List::List()
: mySize(0)
{}

//--- Definition of empty()
bool List::empty() const {
	return (mySize == 0);
}

//--- Definition of display()
void List::display(ostream & out) const {
	for (int i = 0; i < mySize; i++)
		out << myArray[i] << "  ";
}

//--- Definition of output operator
ostream & operator<< (ostream & out, const List & aList) {
	aList.display(out);
	return out;
}

//--- Definition of insert()
void List::insert(ElementType item, int pos) {
	if (mySize == CAPACITY) {
		cerr << "*** No space for list element -- terminating "
		"execution ***\n";
		exit(1);
	}
	if (pos < 0 || pos > mySize) {
		cerr << "*** Illegal location to insert -- " << pos
			<< ".  List unchanged. ***\n";
		return;
	}
	
	// First shift array elements right to make room for item
	for(int i = mySize; i > pos; i--)
		myArray[i] = myArray[i - 1];
	
	// Now insert item at position pos and increase list size
	myArray[pos] = item;
	mySize++;
}

// Definition of erase()
void List::erase(int pos) {
	if (mySize == 0) {
		cerr << "*** List is empty ***\n";
		return;
	}
	if (pos < 0 || pos >= mySize) {
		cerr << "Illegal location to delete -- " << pos
			<< ".  List unchanged. ***\n";
		return;
	}
	
	// Shift array elements left to close the gap
	for(int i = pos; i < mySize; i++)
		myArray[i] = myArray[i + 1];
	
	// Decrease list size
	mySize--;
}

// Addition: in-class example
// Add two List objects together by
//  (1) adding corresponding elements, then
//  (2) copying extra elements from larger list
List List::operator+(const List &rhs) {
	List result;	// Result of add operation
	int minSize;	// Minimum of two list sizes
	int flag = 0;	// Flag indicating larger array
	int i;			// Loop index
	
	if (mySize > rhs.mySize) {		// LHS larger
		result.mySize = mySize;
		minSize = rhs.mySize;
	}
	else {							// RHS larger or equal
		result.mySize = rhs.mySize;
		minSize = mySize;
		flag = 1;
	}
	
	// Add corresponding elements
	for (i = 0; i < minSize; i++)
		result.myArray[i] = myArray[i] + rhs.myArray[i];
	
	// For remaining elements, copy from larger array
	// Note that if arrays same size, loop will not run
	for (i = minSize; i < result.mySize; i++) {
		if (flag == 1)
			result.myArray[i] = rhs.myArray[i];
		else
			result.myArray[i] = myArray[i];
	}
	
	return result;
}


// Input: in-class example
// Assume user enters series of elements separated
//   by spaces, with newline after last element
istream & operator>>(istream &in, List &aList) {
	int i = 0;		// Array index
	
	// Keep reading until next character is newline
	// Newline indicates last value has been entered
	while (in.peek() != '\n') {
		in >> aList.myArray[i++];
		
		if (i == CAPACITY)	// Test for full list; exit loop at that point
			break;
	}
	aList.mySize = i;	// Size = # of values read
	
	cin.ignore(1);		// Remove newline at end of list to allow
						//   multiple lists to be read, e.g.
						//   cin >> L1 >> L2
	return in;
}

