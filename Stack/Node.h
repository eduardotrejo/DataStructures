/*
 Developer: Trejo, Eduardo
 ID: 6787
 Course: CST 238
 Assignment: hw06
 Date: 2014-03-30
 Abstract: This part of the project contains the Node class. It uses friend so the NodeStack can access it's private members. 
		   It Sets a default constructor.
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
	// Gives NodeStack access to value and next.
	friend class NodeStack;
	// Default constructor.
	Node(){ next = NULL; value = 0;}
};
#endif