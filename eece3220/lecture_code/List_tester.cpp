//
//  List_tester.cpp
//  ds_test
//
//  Created by Michael Geiger on 3/1/17.
//  Copyright © 2017 Michael Geiger. All rights reserved.
//

#include "LList.h"

#include <iostream>
using std::cout;
using std::cin;

int main() {
	LList L1, L2;
	
	cout << "L1: ";
	L1.display(cout);		// Print empty list
	
	// Testing insert
	cout << "Inserting 3, 2, 7, and 0\n";
	L1.insert(3);
	L1.insert(2);
	L1.insert(7);
	L1.insert(0);
	cout << "L1: ";
	L1.display(cout);
	
	// Testing assignment
	cout << "Copying L1 to L2\n";
	L2 = L1;
	cout << "L2: ";
	L2.display(cout);
	
	// Testing copy constructor
	cout << "Copying L1 to new LList L3\n";
	LList L3 = L1;
	cout << "L3: ";
	L3.display(cout);
	
	// Testing deletion
	cout << "Removing 2, 3, and 5 (5 isn't in list)\n";
	L1.remove(2);
	L1.remove(3);
	L1.remove(5);
	cout << "L1: ";
	L1.display(cout);
	cout << "L2: ";
	L2.display(cout);
	
	return 0;
}
