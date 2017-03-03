//
//  List.cpp
//   (NOTE: FILE NAME IS DList.cpp JUST TO ALLOW IT TO EXIST IN
//    SAME DIRECTORY AS STATIC ARRAY-BASED LIST. IN PRACTICE,
//    PROGRAM WOULD ONLY USE ONE OR THE OTHER, AND YOU'D NAME
//    THAT FILE List.cpp)

//  ds_test
//
//  Created by Michael Geiger on 2/24/17.
//  Figure 6.2B from Nyhoff text
//

#include <cassert>
#include <new>			// Necessary for (nothrow) version of new
using namespace std;

#include "DList.h"

//--- Definition of class constructor
List::List(int maxSize)
: mySize(0), myCapacity(maxSize)
{
	myArrayPtr = new(nothrow) ElementType[maxSize];
	assert(myArrayPtr != 0);
}

//--- Definition of class destructor
List::~List() {
	delete [] myArrayPtr;
}

//--- Definition of the copy constructor
List::List(const List & origList)
: mySize(origList.mySize), myCapacity(origList.myCapacity) {
	//--- Get new array for copy
	myArrayPtr = new(nothrow) ElementType[myCapacity];
	
	if (myArrayPtr != 0)                 // check if memory available
		//--- Copy origList's array into this new array
		for(int i = 0; i < myCapacity; i++)
			myArrayPtr[i] = origList.myArrayPtr[i];
	else {
		cerr << "*Inadequate memory to allocate List ***\n";
		exit(1);
	}
}

//--- Definition of the assignment operator
List & List::operator=(const List & origList) {
	if (this != &origList) {   // check for list = list
		mySize = origList.mySize;
		myCapacity = origList.myCapacity;
		
		//-- Allocate a new array if necessary
		if (myCapacity != origList.myCapacity)
		{
			delete[] myArrayPtr;
			myArrayPtr = new(nothrow) ElementType[myCapacity];
			
			if (myArrayPtr == 0)   // check if memory available
			{
				cerr << "*Inadequate memory to allocate stack ***\n";
				exit(1);
			}
		}
		//--- Copy origList's array into this new array
		for(int i = 0; i < myCapacity; i++)
			myArrayPtr[i] = origList.myArrayPtr[i];
	}
	return *this;
}

//--- Definition of empty()
bool List::empty() const {
	return mySize == 0;
}

//--- Definition of display()
void List::display(ostream & out) const {
	for (int i = 0; i < mySize; i++)
		out << myArrayPtr[i] << "  ";
}

//--- Definition of output operator
ostream & operator<< (ostream & out, const List & aList) {
	aList.display(out);
	return out;
}

//--- Definition of insert()
void List::insert(ElementType item, int pos) {
	if (mySize == myCapacity) {
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
		myArrayPtr[i] = myArrayPtr[i - 1];
	
	// Now insert item at position pos and increase list size
	myArrayPtr[pos] = item;
	mySize++;
}

//--- Definition of erase()
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
		myArrayPtr[i] = myArrayPtr[i + 1];
	
	// Decrease list size
	mySize--;
}