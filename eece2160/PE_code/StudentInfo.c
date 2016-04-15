//
//  StudentInfo.c
//  PE4_structures
//
//  Created by Michael Geiger on 4/8/16.
//  Copyright © 2016 Michael Geiger. All rights reserved.
//

#include "StudentInfo.h"
#include <stdio.h>
#include <string.h>

// Print information about student
void printStudent(StudentInfo *s) {
	printName(&s->sname);
	printf("ID #%.8u\n", s->ID);
	printf("GPA: %.2lf\n", s->GPA);
}

// Reads student information into existing structure
void readStudent(StudentInfo *s) {
	readName(&s->sname);
	printf("Enter ID #: ");
	scanf("%u", &s->ID);
	printf("Enter GPA: ");
	scanf("%lf", &s->GPA);
}

// Print list of students
void printList(StudentInfo list[], int n) {
	int i;	// Loop index
	
	for (i = 0; i < n; i++) {
		printStudent(&list[i]);
		printf("\n");			// Add extra blank line between students
	}
}

// Find student in list, based on last name
// Returns index if student found, -1 otherwise
int findByLName(StudentInfo list[], int n, char lname[]) {
	int i;	// Loop index
	
	// Search for student with matching last name in list
	for (i = 0; i < n; i++) {
		if (strcmp(lname, list[i].sname.last) == 0)
			return i;
	}
	
	// If end of loop reached, student wasn't found
	return -1;
}

// Find student in list, based on ID #
// Returns index if student found, -1 otherwise
int findByID(StudentInfo list[], int n, unsigned int sID) {
	int i;	// Loop index
	
	// Search for student with matching ID in list
	for (i = 0; i < n; i++) {
		if (sID == list[i].ID)
			return i;
	}
	
	// If end of loop reached, student wasn't found
	return -1;
}
