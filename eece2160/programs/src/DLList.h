/*************************************************
   EECE.2160: ECE Application Programming
   UMass Lowell
   M. Geiger
   Header file for 10th programming assignment
   Contains structure definitions, function prototypes

********DO NOT MODIFY THIS FILE ********

**************************************************/

// Structure definitions
// Node in doubly-linked list
typedef struct DLN {
	struct DLN *prev;		// Pointer to previous list element
	struct DLN *next;		// Pointer to next list element
	double val1;			// First value in node
	double val2;			// Second value in node
} DLNode;

// Actual doubly-linked list
typedef struct {
	DLNode *firstNode;	// Pointer to first node in list
	DLNode *lastNode;	// Pointer to last node in list
} DLList;

// Function prototypes
DLNode *findFWD(DLList *list, double v, int *num);	// Find node containing v, searching from 1st node
													// Argument num points to number of iterations
DLNode *findREV(DLList *list, double v, int *num);	// Find node containing v, searching from last node
													// Argument num points to number of iterations
void addNode(DLList *list, double v1, double v2);	// Add new node containing v1, v2
void delNode(DLList *list, double v);				// Delete node containing v from list
void printFWD(DLList *list);						// Print contents of list, starting with 1st node
void printREV(DLList *list);						// Print contents of list, starting with last node
void freeList(DLList *list);						// Frees entire list to avoid memory leaks