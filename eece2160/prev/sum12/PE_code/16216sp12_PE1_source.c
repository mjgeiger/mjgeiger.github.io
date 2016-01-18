/* 
 * 16.216: ECE Application Programming
 * Instructor: M. Geiger
 * Source code for PE1 (Flowcharts, basic debugging)
 * 2/3/2012
 */

#include <stdio.h>

void main() {

	double num1, num2, num3, num4;	// Input variables

	/* Prompt for and read input values */
	printf("Enter 4 numbers on single line: ");
	scanf("%lf %lf %lf %lf", 
		&num1, &num2, &num3, &num4);

	/* Print numbers in matrix form */
	printf(" %lf  %lf\n", num1, num2);
	printf(" %lf  %lf\n", num3, num4);

	/* Print discriminant */
	printf("Discriminant: %lf\n", (num1 * num4) - (num2 * num3));
}