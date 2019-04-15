/*
 * M. Geiger
 * EECE.3220: Data Structures
 *
 * Source file for in-class queue example
 * Queue function definitions for array-based queue
 *
 * ASSUMPTIONS:
 *   Each index (front/back) = position to access next
 *   Wasting one spot in array (so full/empty depends
 *     on positions)
 */

#include <iostream>
using std::cout;

#include "LQueue.h"

// Constructor
// Default value for maxSize = 1024
Queue::Queue() : front(NULL), back(NULL)
{}

// Destructor
Queue::~Queue() {
	// Delete ***all*** the nodes
}

// Returns true if queue empty
bool Queue::empty() const {
	return (front == NULL);
}

// Add val to back of queue
void Queue::enqueue(const QueueElement &val) {
	// Allocate new node
	Node *newNode;
	newNode = new Node;
	newNode->data = val;
	newNode->next = NULL;

	// SPECIAL CASE WHEN GOING FROM 0 --> 1 NODE
	if (empty())
		front = newNode;

	// Otherwise, old "back" node points to new node
	else
		back->next = newNode;

	// "back" pointer points to new node
	back = newNode;

}

// Remove head of queue
void Queue::dequeue() {
	if (!empty()) {
		// ptr = address of front node

		// "front" ptr = address of second node

		// delete old front node (ptr = address of that node)
	}

	else
		cout << "Tried to dequeue() from an empty queue\n";
}

// Read contents of front of queue
QueueElement Queue::getFront() {
	if (!empty())
		return front->data;
	else {
		cout << "ERROR: Queue empty\n";
		Node temp;
		return temp.data;
	}
}