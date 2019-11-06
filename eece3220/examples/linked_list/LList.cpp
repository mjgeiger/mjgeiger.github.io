/*
 * EECE.3220: Data Structures
 * Instructor: M. Geiger
 * Linked list definition
 *
 * LList.cpp: function definitions
 */
 
#include "LList.h"
using namespace std;

 // Default constructor
LList::LList() : first(NULL)
{}

// Destructor
LList::~LList() {
	Node *temp;
	while (first != NULL) {
		temp = first;
		first = first->next;
		delete temp;
	}
}

// True if list is empty
bool LList::empty() {
	return (first == NULL);
}

// Add new value to list
void LList::insert(int v) {
	Node *curr = first;		// Leading pointer in list traversal
							// Finds successor of new node
	Node *prev = NULL;		// Trailing pointer in list traversal
							// Finds predecessor of new node

	// Allocate new node and store input argument
	Node *newNode = new Node;
	newNode->val = v;

	// Find appropriate spot for new node
	// curr will point to successor when done
	while (curr != NULL &&
		curr->val < newNode->val)
	{
		prev = curr;
		curr = curr->next;
	}

	if (prev == NULL)
		first = newNode;
	else
		prev->next = newNode;  // pred -> new
	newNode->next = curr;  // new -> succ

}

// Remove node with v	
void LList::remove(int v) {
	Node *prev;		// Predecessor of node to be deleted
	Node *cur;		// Node to be deleted

	// Find node, if it's in list
	cur = first;
	prev = NULL;
	while (cur != NULL && cur->val < v) {
		prev = cur;
		cur = cur->next;
	}

	// Didn't find node
	if (cur == NULL || cur->val > v) {
		cout << "Node with value " << v << " not found\n";
		return;
	}

	// Otherwise, remove node
	if (prev == NULL)			// Special case for first node
		first = cur->next;
	else
		prev->next = cur->next;
	delete cur;
}

// Display contents of list
void LList::display(ostream &out) {
	Node *ptr = first;

	while (ptr != NULL) {
		out << ptr->val << '\n';
		ptr = ptr->next;
	}
}