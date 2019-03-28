/*
 * EECE.2160: ECE Application Programming
 * Short example program to illustrate use
 *   of pointer arguments
 * Main function
 * 
 * Written 3/19/19 by M. Geiger
 */

#define _CRT_SECURE_NO_WARNINGS		// Remove scanf() warnings on Visual Studio
#include <stdio.h>

#include "ptr_args.h"

int main() {
	int i1, i2;
	double d1, d2, d3;
	
	// Testing function with return value & pointer argument
	i1 = 10;
	i2 = f(&i1);

	// Testing function with no return value, multiple pointer arguments
	d1 = 21.60;
	d2 = 5.5;
	d3 = 32.20;
	f2(&d1, &d2, &d3);
	
	return 0;
}