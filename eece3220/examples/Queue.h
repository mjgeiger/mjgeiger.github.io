/*
 * M. Geiger
 * EECE.3220: Data Structures
 *
 * Header file for in-class queue example
 * Queue class definition for array-based queue
 * 
 * ASSUMPTIONS:
 *   Each index (front/back) = position to access next
 *   Wasting one spot in array (so full/empty depends
 *     on positions)
 */

#ifndef QUEUE_H
#define QUEUE_H

typedef double QueueElement;

class Queue {
public:
	Queue(unsigned maxSize = 1024);			// Constructor
	~Queue();								// Destructor
	bool empty() const;						// Returns true if queue empty
	void enqueue(const QueueElement &val);	// Add val to back of queue
	void dequeue();							// Remove head of queue
	QueueElement getFront();				// Read contents of front of queue
private:
	QueueElement *list;	// The actual data stored in the queue
	int front, back;	// Indexes for head & tail of queue
	unsigned cap;		// Capacity (max size) of queue
};

#endif   // QUEUE_H
