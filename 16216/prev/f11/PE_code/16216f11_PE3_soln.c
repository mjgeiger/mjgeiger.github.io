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

#include <stdio.h>
#include <math.h>		// Used for sqrt() function

// Min, max # points to be read in
#define MinPts 1
#define MaxPts 52

int main() {

	/* Variable declarations */
	char repeat;				// Indicates if we're reading another
								//   group of points
	char junk;					// Used for clearing line
	int n;						// Holds # variables read by scanf()
	int nPts;			 		// Total # points to be read
	int nRead;					// # points read so far
	int nValid;					// # valid points read so far
								//   Can only calculate distance if
								//    current point is valid and nValid > 0
								//    (at least one previous valid point)
	double totalDist;			// Total distance traveled
	char letter;				// Label for each point
	double x, y;				// Current x, y coordinates
	double lastX, lastY;		// x, y coordinates from previous iteration

	do {	// Repeats until user enters 'N' when asked to repeat
	
		// Read in total # of points and check for errors
		do {
			printf("Enter total # of points: ");
			n = scanf("%d", &nPts);
	
			if (n < 1) {		// Input is incorrectly formatted
				printf("Error: # points incorrectly formatted\n");
				do {
					scanf("%c", &junk);
				} while (junk != '\n');
			}
	
			else if ((nPts < MinPts) || (nPts > MaxPts)) {
				printf("Error: # points out of range\n");
			}

		} while ((n < 1) || (nPts < MinPts) || (nPts > MaxPts));
	
		// Clear newline
		scanf("%c", &junk);

		// Read in list of points
		totalDist = 0;
		nValid = 0;
		for (nRead = 0; nRead < nPts; nRead++) {
			
			// Prompt user to enter point as <letter> <x coord> <y coord>
			printf("Enter a point: ");
			n = scanf("%c %lf %lf", &letter, &x, &y);
	
			// Point is invalid--print error message and clear line
			if (n < 3) {
				printf("Error: Point incorrectly formatted\n");
				do {
					scanf("%c", &junk);
				} while(junk != '\n');
			
				continue;			/* Skips rest of loop body (distance
									     calculation, increment nValid, 
									     store point from this iteration
									     for use in next iteration)
										 but allows this point to count
										 in overall total */
			}

			// At least one previously valid point--calculate
			//    new distance and add to totalDist
			if (nValid > 0) {
				// Calculate new distance and add to totalDist
				totalDist += sqrt((x - lastX) * (x - lastX) + 
								(y - lastY) * (y - lastY));
			}

			// Point read in this iteration was valid--store x and y
			//   values in lastX and lastY, and increment nValid
			lastX = x;
			lastY = y;
			nValid++;

			// Clear newline--otherwise, you won't be able to
			//   read next point correctly
			scanf("%c", &junk);
		}

		printf("Total distance traveled: %lf\n", totalDist);
	
		// Ask user to repeat process; keep asking until valid response given
		do {
			printf("Would you like to enter another set of points? ");
			scanf("%c", &repeat);
			if ((repeat == 'Y') || (repeat == 'N')) 
				break;

			// Implied else--if you get here, repeat is invalid
			printf("Error: invalid response; please enter Y or N\n");
		} while (1);

	} while (repeat == 'Y');

	return 0;
}