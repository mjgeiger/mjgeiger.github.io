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

// Linked queue
class Queue {
public:
	Queue();								// Constructor
	~Queue();								// Destructor
	bool empty() const;						// Returns true if queue empty
	void enqueue(const QueueElement &val);	// Add val to back of queue
	void dequeue();							// Remove head of queue
	QueueElement getFront();				// Read contents of front of queue
private:
	class Node {			// Queue node
	public:
		QueueElement data;
		Node *next;
	};
	Node *front, *back;		// Addresses of front/back of queue
};

#endif   // QUEUE_H