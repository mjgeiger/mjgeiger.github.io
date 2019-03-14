#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

double d1;	// Global variable--NOT A GOOD IDEA

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include "basic_functions.h"

int main() {
	int x, y;

	x = f1();	
	y = x / 2;
	f1();
	f2(x, y);
	printf("x = %d, y = %d\n", x, y);
	return 0;
}