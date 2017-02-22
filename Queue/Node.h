/*
 Developer: Trejo, Eduardo
 ID: 6787
 Course: CST 238
 Assignment: hw07
 Date: 2014-04-07
 Abstract: This part of the program contains the private elements; int value and Node *next pointer. It uses friend class so Queue.h has 
		   access to the private variables.
 */
#ifndef NODE_H_
#define NODE_H_

class Node
{
private:
	// Stores value/data.
	int value;
	// Create a node pointer, will point to next node in the list.
	Node *next;
public:
	// Gives Queue access to value and next.
	friend class Queue;
	// Default constructor.
	Node(){ next = NULL; value = 0;}
};
#endif