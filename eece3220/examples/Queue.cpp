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

#include "Queue.h"

// Constructor
// Default value for maxSize = 1024
Queue::Queue(unsigned maxSize) : front(0), back(0), cap(maxSize)
{
	list = new QueueElement[cap];
}

// Destructor
Queue::~Queue() {
	delete[] list;
}

// Returns true if queue empty
bool Queue::empty() const {
	return (front == back);
}

// Add val to back of queue
void Queue::enqueue(const QueueElement &val) {
	if (front == (back + 1) % cap)		// Queue full
		cout << "ERROR: Queue full\n";
	else {
		list[back] = val;
		back = (back + 1) % cap;
	}
}

// Remove head of queue
void Queue::dequeue() {
	if (empty())
		cout << "ERROR: Queue empty\n";
	else
		front = (front + 1) % cap;
}

// Read contents of front of queue
QueueElement Queue::getFront() {
	if (empty()) {
		cout << "ERROR: Queue empty\n";
		return list[cap - 1];
	}
	else
		return list[front];
}