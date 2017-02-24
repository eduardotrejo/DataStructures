/*
 Developer: Trejo, Eduardo
 Date: 2014-05-05
 Abstract: This part of the program contains the private elements; int value, Node *left, and Node *right pointer. It uses friend
		   class so Tree.h has access to the private variables.
 */
#ifndef _NODE_H_
#define _NODE_H_

class Node
{
private:
	int value;
	// Create a node pointer, for left and right subtree.
	Node *left;
	Node *right;
public:
	friend class Tree;
	// Default constructor.
	Node(){ left = NULL; right = NULL; value = NULL;}
};
#endif
