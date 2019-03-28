/*
 * EECE.2160: ECE Application Programming
 * Short example program to illustrate use
 *   of pointer arguments
 * Function prototypes
 *
 * Written 3/19/19 by M. Geiger
 */

// Prototype for function with a return value
//   and pointer argument
int f(int *addr_y);

// Prototype for function that returns nothing
//   but can still modify values through 
//   multiple pointer arguments
void f2(double *ptr1, double *ptr2, double *ptr3);