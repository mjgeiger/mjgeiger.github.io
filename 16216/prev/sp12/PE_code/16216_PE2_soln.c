/* 
 * 16.216: ECE Application Programming
 * Instructor: M. Geiger
 * Source code for PE2 (Formatting, conditional statements)
 * 2/17/2012
 */

#include <stdio.h>
#include <math.h>

void main() {
	// Variables
	double A, B, C;		// Coefficients of equation
						//   of form Ax^2 + Bx + C
	double disc;		// Discriminant of equation

	// Print introductory message and prompt
	printf("Quadratic Equation Solver\n");
	printf("Enter A, B, C:  ");
	scanf("%lf %lf %lf", &A, &B, &C);

	// Check first coefficient; if 0, print single root
	if (A == 0) {
		printf("\nRoot: %.2lf\n", -C / B);
	}

	// Otherwise, calculate discriminant and other roots accordingly
	else {
		disc = B * B - 4 * A * C;

		// If discriminant == 0, print single root
		if (disc == 0)
			printf("\nRoot: %.2lf\n", -B / (2*A));

		// If discriminant > 0, print 2 real roots
		else if (disc > 0) 
			printf("\nRoots: %.2lf, %.2lf\n", (-B + sqrt(disc)) / (2 * A),
					(-B - sqrt(disc)) / (2 * A));
		
		// Otherwise, print 2 imaginary roots
		else
			printf("\nRoots: %.2lf + %.2lfi, %.2lf - %.2lfi\n",
					-B / (2*A), sqrt(-disc) / (2*A),
					-B / (2*A), sqrt(-disc) / (2*A));
	}
}