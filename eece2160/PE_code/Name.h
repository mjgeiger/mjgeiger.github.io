//
//  Name.h
//  PE4_structures
//
//  Created by Michael Geiger on 4/8/16.
//  Copyright © 2016 Michael Geiger. All rights reserved.
//

#ifndef Name_h
#define Name_h

typedef struct {
    char first[50];
    char middle;
    char last[50];
} Name;

// Print contents of Name struct
void printName(Name *n);

// Read information into existing Name
void readName(Name *n);

#endif /* Name_h */
