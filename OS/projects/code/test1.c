//
//  test1.c
//
//
//  Created by Michael Geiger on 4/13/17.
//  Simple program to be run in OS Project 1
//

#include <stdio.h>
#include <unistd.h>

int main() {
	printf("Running program test1 in process %d\n", (int)getpid());
	for (int i = 0; i < 10; i++)
		printf("T1 i %d, i^2 %d\n", i, i*i);
	return 0;
}