/*
 Developer: Trejo, Eduardo
 Date: 2014-03-23
 Abstract: This program constructs a Node class.
 */
#ifndef NODE_H_
#define NODE_H_

#include <iostream>
using namespace std;
class Node
{
private:
	// Stores value/data.
	int value;
	// Create a node pointer, will point to next node in the list.
	Node *next;
public:
	// Gives NodeList access to value and next.
	friend class NodeList;
	Node(){ next = NULL; value = 0;}
	// Retrieve value for this node.
	int getValue() const { return value;}
	// Retrieve next Node in the list.
	Node *getNext() const { return next;}
	// Use to modify the the value stored in the list.
	void setValue(int v){ value = v;}
	// Use to change the reference to the next node.
	void setNext(Node* newNode){ next = newNode;}
};
#endif
