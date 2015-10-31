/*
 * 16.216 ECE Application Programming
 * Starter file by M. Geiger to
 *   raster graphics programming assignment
 * Implements simple raster scan graphics program--
 *    will print box and grid, line by line
 * Tests use of 2-D arrays, nested loops, strings
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "prog7_functions.h"


int main() {
    char myGrid[NRows][NCols];
    
    /****** 16.216 PROGRAM **********
     ADD ADDITIONAL VARIABLES HERE
     ********************************/
    
    resetGrid(myGrid);			// Initialize grid to clear state
    
    /******* 16.216 PROGRAM **********
     LOOP TO REPEATEDLY PROMPT FOR AND EXECUTE INPUT COMMANDS
     *********************************/
    
    /***** 16.216 PROGRAM **********
     PROMPT FOR AND READ INPUT COMMAND
     *******************************/
    
    /***** 16.216 PROGRAM **********
     "print" COMMAND ENTERED--PRINT CURRENT STATE OF GRID
     *******************************/
    
    /***** 16.216 PROGRAM ***********
     "reset" COMMAND ENTERED--RESET GRID TO HAVE NO BOXES
     *********************************/
    
    /***** 16.216 PROGRAM ***********
     "add" COMMAND ENTERED--PROMPT FOR ORIGIN
     COORDINATES (X,Y), WIDTH, AND HEIGHT, THEN
     ADD BOX TO GRID
     **********************************/
    
    /***** 16.216 PROGRAM ***********
     "exit" COMMAND ENTERED--END PROGRAM
     **********************************/
    
    /***** 16.216 PROGRAM ***********
     NO MATCHING COMMAND--PRINT ERROR
     *********************************/
    
    /***** 16.216 PROGRAM **********
     END LOOP
     ********************************/
    
    return 0;
}