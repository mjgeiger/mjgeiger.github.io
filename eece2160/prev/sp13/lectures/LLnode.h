/*************************************************
   16.216: ECE Application Programming
   UMass Lowell
   M. Geiger
   Header file for PE6: Dynamic memory allocation
   and data structures

   Contains LLnode structure definition, as well 
   as function prototypes
**************************************************/

// Node definition for singly linked list of integers
typedef struct node {
	int value;
	struct node *next;
} LLnode;

// Function prototypes
LLnode *addNode(LLnode *list, int v);		// Add integer to list (unsorted)
											//   and return pointer to new start of list
LLnode *findNode(LLnode *list, int v);		// Find node in list and return pointer
											//   (or NULL if not found)
LLnode *delNode(LLnode *list, int v);		// Delete node from list (if present)
void printList(LLnode *list);				// Print contents of entire list

LLnode *addSortedNode(LLnode *list, int v);		// Keep list sorted in ascending order 
												//   and add integer; return pointer to
												//   start of list
LLnode *findSortedNode(LLnode *list, int v);	// Find node in sorted list and return pointer
												//   (or NULL if not found)