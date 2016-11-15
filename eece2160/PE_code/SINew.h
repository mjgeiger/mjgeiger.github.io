//
//  SINew.h (previously StudentInfo.h)
//  PE4_structures
//
//  Created by Michael Geiger on 4/8/16.
//  Revised 11/15/16: Rename StudentInfo type to SINew
//  Copyright © 2016 Michael Geiger. All rights reserved.
//

#ifndef SINew_h
#define SINew_h

#include "Name.h"	// Allows use of Name structure, functions

// SINew structure definition
typedef struct {
    Name sname;
    unsigned int ID;
    double GPA;
} SINew;

// Print information about student
void printStudent(SINew *s);

// Reads student information into existing structure
void readStudent(SINew *s);

// Print list of students
void printList(SINew list[], int n);

// Find student in list, based on last name
// Returns index if student found, -1 otherwise
int findByLName(SINew list[], int n, char lname[]);

// Find student in list, based on ID #
// Returns index if student found, -1 otherwise
int findByID(SINew list[], int n, unsigned int sID);

#endif /* SINew_h */
