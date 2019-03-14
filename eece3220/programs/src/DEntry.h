/*
	EECE.3220: Data Structures
	M. Geiger
	Instructor solution for Program 2: Dictionary

	Dictionary entry class (DEntry) definition
*/

#ifndef DEntry_h
#define DEntry_h

#include <string>
using std::string;

#include <iostream>
using std::ostream;

class DEntry {
public:
	void writeEntry(string w, string p, string d);	// Write data to entry
	void printEntry(ostream &out);					// Print contents of entry
	string getWord();								// Access word
private:
	string word;		// Word
	string part;		// Part of speech
	string defn;		// Definition
};

#endif	// DEntry_h