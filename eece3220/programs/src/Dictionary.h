/*
	EECE.3220: Data Structures
	M. Geiger
	Instructor solution for Program 2: Dictionary

	Dictionary class definition
*/

#ifndef Dictionary_h
#define Dictionary_h

#include <iostream>
using std::ostream;

#include "DEntry.h"		// Implicitly includes <string>

class Dictionary {
public:
	Dictionary();
	bool addWord(string w, string p, string d);		// Add word to dictionary
	bool addFile(string fname);						// Add file contents to dictionary
													//  Both functions return true if successful
	bool find(DEntry &entry, string word);			// Find entry containing word
	void printAll(ostream &out);					// Print all entries
	void printLetter(ostream &out, char letter);	// Print all entries with word starting
													//  with letter
private:
	DEntry entries[100];		// Array of dictionary entries		
	unsigned size;				// Number of entries currently in dictionary
	unsigned posn(string w);	// Position in which word w either exists or should be placed
};

#endif  // Dictionary_h