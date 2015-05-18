/*
 * 16.216: ECE Application Programming, University of Massachusetts Lowell
 * Instructor: Dr. Michael Geiger
 *
 * 10/19/11: Programming Exercise 3
 * Program is intended to give students practice with loops
 *
 * Given a series of points, calculate the total distance traveled between
 *   all points. Note that, given a pair of coordinates (x_1, y_1) and 
 *   (x_2, y_2) the distance between them is:
 *       sqrt((x_2 - x_1)^2 + (y_2 - y_1)^2)
 * Points will be given in the form:
 *   <letter> <x coordinate> <y coordinate>
 */

#include <stdio.h>
#include <math.h>		// Used for sqrt() function

int main() {

	/* PROGRAM SHOULD BE STRUCTURED AS FOLLOWS: 
		--First, program should read the number of points to be entered
		    --> Ensure this number falls within an appropriate range;
			    if not, user should re-enter
		--Program should then read all points and keep a running sum
		  of the total distance traveled
		    --> If a point is entered incorrectly, it must not be allowed 
			    to update the total distance. However, that point does
				count against the total number of points read in.
				(For example, if the user enters 10 as the number of
				points, and 2 of those values are entered incorrectly,
				your program shouldn't skip those two and end up trying
				to read a total of 12 points.)
		--After the total distance is calculated, print it (using precision 2)
		--The user should then be asked if he/she would like to enter
		  another series of points.
		     --> If the answer is 'Y', repeat the steps above
			 --> If the answer is 'N', exit the program
			 --> If the answer is neither 'Y' nor 'N', print an error and repeat the prompt
	*/

	return 0;
}