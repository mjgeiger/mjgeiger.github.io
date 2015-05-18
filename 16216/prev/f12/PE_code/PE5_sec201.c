/*************************************************
   16.216: ECE Application Programming
   UMass Lowell
   M. Geiger
   PE5: Working with I/O
   Section 201 solution
**************************************************/

#include <stdio.h>
#include <stdlib.h>

FILE *openFile(char *mode);		// Used for opening files; exiting program if appropriate

void main() {
	int arr[20];				// Input array for use with binary file
	int test;					// Input/output value for formatted I/O

	FILE *fpArr;				// Pointer to binary file holding array values
	FILE *fpIn;					// Pointer to file holding test input values
	FILE *oFile;				// Pointer to output file
	int i;

	// CALL openFile() TO OPEN FILE WITH ARRAY
	fpArr = openFile("rb");

	// READ CONTENTS OF ARRAY FROM FILE
	fread(arr, sizeof(int), 20, fpArr);

	// CALL openFile() TO OPEN FILE WITH TEST INPUT VALUES
	fpIn = openFile("r");

	// CALL openFile() TO OPEN OUTPUT FILE
	oFile = openFile("w");

	// READ 20 VALUES FROM TEST INPUT FILE
	// FOR EACH ONE, PRINT THE FOLLOWING TO OUTPUT FILE:
	//    <test> + <appropriate array value> = <sum>
	// FOR EXAMPLE, IF FIRST TEST VALUE IS
	//   5 AND ARR[0] = 6, PRINT
	//    5 + 6 = 11
	i = 0;
	while (fscanf(fpIn, "%d", &test) != EOF) {
		fprintf(oFile, "%d + %d = %d\n", test, arr[i], test + arr[i]);
		i++;
	}

	// CLOSE ANY OPEN FILES
	fclose(fpArr);
	fclose(fpIn);
	fclose(oFile);
}

FILE *openFile(char *mode) {	
	char fname[50];
	FILE *fp;

	/****** 
	  COMPLETE THIS FUNCTION SO THAT IT:
	    - READS THE NAME OF THE FILE TO BE OPENED
		- OPENS THAT FILE USING THE MODE SPECIFIED AS AN ARGUMENT
		- EXITS PROGRAM IF FILE DOESN'T OPEN
		- RETURNS POINTER TO FILE IF IT DOES OPEN
	******/
	printf("Enter file name:  ");
	scanf("%s", fname);
	fp = fopen(fname, mode);
	if (fp == NULL) {
		printf("Invalid file name %s; exiting program\n", fname);
		exit(0);
	}

	return fp;
}