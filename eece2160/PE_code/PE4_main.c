//
//  main.c
//  PE4_structures
//
//  Created by Michael Geiger on 4/8/16.
//  Copyright © 2016 Michael Geiger. All rights reserved.
//

#include <stdio.h>
#include "SINew.h"

int main() {
	char cmd, cmd2;			// Single character commands
	SINew stList[10];	// List of students
	int nS = 0;				// Number of students in list
	unsigned int searchID;	// ID to find student by
	char searchLN[50];		// Last name to find student by
	int index;				// Index of found student
	
	// Loop until user enters 'Q'
	while (1) {
		printf("\nEnter command <A | P | F | Q>: ");
		scanf(" %c", &cmd);
		
		switch (cmd) {
				
			// Add student
			case 'A': case 'a':
				if (nS == 10)		// List is full
					printf("No room in student list\n");
				else {
					printf("Enter student information:\n");
					readStudent(&stList[nS]);
					nS++;
				}
				break;
				
			// Print list
			case 'P': case 'p':
				if (nS == 0)		// List is empty
					printf("No students in list\n");
				else
					printList(stList, nS);
				break;
				
			// Find student
			case 'F': case 'f':
				printf("Enter I to find by ID, L to find by last name: ");
				scanf(" %c", &cmd2);
		
				switch (cmd2) {
					case 'I': case 'i':
						printf("Enter search ID: ");
						scanf("%u", &searchID);
						index = findByID(stList, nS, searchID);
						break;
						
					case 'L': case 'l':
						printf("Enter last name: ");
						scanf("%s", searchLN);
						index = findByLName(stList, nS, searchLN);
						break;
						
					default:
						printf("Invalid selection\n");
						do {
							scanf("%c", &cmd2);
						} while (cmd2 != '\n');
						index = -2;
				}
				
				// Check results of find function
				if (index == -1)
					printf("Student not found\n");
				else if (index >= 0) {
					printf("Student found\n");
					printStudent(&stList[index]);
				}
				break;
				
			// Exit program
			case 'Q': case 'q':
				return 0;
				
			default:
				printf("Invalid command %c\n", cmd);
		}
	}
}
