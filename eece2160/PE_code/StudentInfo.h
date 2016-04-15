//
//  StudentInfo.h
//  PE4_structures
//
//  Created by Michael Geiger on 4/8/16.
//  Copyright © 2016 Michael Geiger. All rights reserved.
//

#ifndef StudentInfo_h
#define StudentInfo_h

#include "Name.h"

// StudentInfo structure definition
typedef struct {
    Name sname;
    unsigned int ID;
    double GPA;
} StudentInfo;

// Print information about student
void printStudent(StudentInfo *s);

// Reads student information into existing structure
void readStudent(StudentInfo *s);

// Print list of students
void printList(StudentInfo list[], int n);

// Find student in list, based on last name
// Returns index if student found, -1 otherwise
int findByLName(StudentInfo list[], int n, char lname[]);

// Find student in list, based on ID #
// Returns index if student found, -1 otherwise
int findByID(StudentInfo list[], int n, unsigned int sID);

#endif /* StudentInfo_h */
