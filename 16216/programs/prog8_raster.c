/*
* 16.216 ECE Application Programming
* prog8_raster.c: Instructor solution by M. Geiger
*   to raster graphics programming assignment
* Implements simple raster scan graphics program--
*    will print box and grid, line by line
* Tests use of 2-D arrays, nested loops, strings
*/

#define NRows 21	// Dimensions for grid
#define NCols 51

#include <stdio.h>
#include <string.h>

/**** FUNCTION PROTOTYPES ****/
// Reset grid to original settings
void resetGrid(char grid[][NCols]);

// Add box to existing grid starting at (x, y) with specified width & height
void addBox(char grid[][NCols], int x, int y, int width, int height);

// Print current grid contents
void printGrid(char grid[][NCols]);
/***** END FUNCTION PROTOTYPES *****/

void main() {
	char myGrid[NRows][NCols];

	/****** 16.216 PROGRAM 8 ******
		ADD ADDITIONAL VARIABLES HERE
	********************************/	

	resetGrid(myGrid);			// Initialize grid to clear state

	/******* 16.216 PROGRAM 8 *******
		LOOP TO REPEATEDLY PROMPT FOR AND EXECUTE INPUT COMMANDS
	*********************************/

		/***** 16.216 PROGRAM 8 *******
			PROMPT FOR AND READ INPUT COMMAND 
		*******************************/
		
		/***** 16.216 PROGRAM 8 *******
			"print" COMMAND ENTERED--PRINT CURRENT STATE OF GRID 
		*******************************/
		
		/***** 16.216 PROGRAM 8 *********
			"reset" COMMAND ENTERED--RESET GRID TO HAVE NO BOXES 
		*********************************/
		
		/***** 16.216 PROGRAM 8 *********
			"add" COMMAND ENTERED--PROMPT FOR ORIGIN 
			COORDINATES (X,Y), WIDTH, AND HEIGHT, THEN
			ADD BOX TO GRID
		**********************************/

		/***** 16.216 PROGRAM 8 *********
			"exit" COMMAND ENTERED--END PROGRAM 
		**********************************/

		/***** 16.216 PROGRAM 8 *********
			NO MATCHING COMMAND--PRINT ERROR 
		*********************************/
		
	/***** 16.216 PROGRAM 8 ********
		END LOOP
	********************************/
}

/***** FUNCTION DEFINITIONS *****/
// Reset grid to original settings
void resetGrid(char grid[][NCols]) {
	/***** 16.216 PROGRAM 8 *****
		COMPLETE FUNCTION 
	*****************************/
}

// Add box to existing grid starting at (x, y) with specified width & height
void addBox(char grid[][NCols], int x, int y, int width, int height) {
	/***** 16.216 PROGRAM 8 *****
		COMPLETE FUNCTION 
	*****************************/
}

// Print current grid contents
void printGrid(char grid[][NCols]) {
	/***** 16.216 PROGRAM 8 *****
		COMPLETE FUNCTION
	*****************************/
}