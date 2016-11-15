//
//  Name.c
//  PE4_structures
//
//  Created by Michael Geiger on 4/8/16.
//  Copyright © 2016 Michael Geiger. All rights reserved.
//

#include "Name.h"
#include <stdio.h>

// Print contents of Name struct
void printName(Name *n) {
	printf("%s %c. %s\n", n->first, n->middle, n->last);
}

// Read information into existing Name
void readName(Name *n) {
	printf("Enter name: ");
	scanf("%s %c. %s", n->first, &n->middle, n->last);
}
