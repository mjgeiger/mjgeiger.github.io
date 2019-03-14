#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include "basic_functions.h"

int f1() {
	int a, b;	// Local variables for f1
	printf("Enter two ints: ");
	scanf("%d %d", &a, &b);
	return a + b;
}

void f2(int v1, int v2) {
	v1 = v1 + 10;
	v2 = v2 - 3;
	printf("v1 = %d, v2 = %d\n", v1, v2);
}

double f3(int val1, int val2, int val3) {
	return (val1 + val2 + val3) / 3.0;
}

void clearLine() {
	char junk;
	do {
		scanf("%c", &junk);
	} while (junk != '\n');
}