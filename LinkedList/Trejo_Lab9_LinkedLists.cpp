// Trejo_Lab9_LinkedLists.cpp : Defines the entry point for the console application.
//Name: Jaime Trejo
//Date:3/19/13
//School:Wentworth Institute of Technology
//Class: Comp 201 Section 11
//Compiler: Microsoft Visual Studio 2012
//Program: This program will create a linked list with a class
//			A linked list is not fixed in size,but can grow and shrink while your program is running. 
//			A linked list is constructed by using pointers.

#include "stdafx.h"
#include <iostream>
using namespace std;

class Node
{
public:
	// Constructors to initialize a node
	Node();
	Node(int value, Node *next);

	int getData() const; // Retrieve value for this node
	Node *getLink( ) const;// Retrieve next Node in the list
	void setData(int value);// Use to modify the value stored in the list
	void setLink(Node *next);// Use to change the reference to the next node
private:
	int data;
	Node *link;
};

typedef Node* NodePtr;
void head_insert(NodePtr &head, int the_number);
 
// linkedlistofclasses
int _tmain(int argc, _TCHAR* argv[])
{
	NodePtr head, tmp;  

	// Create a list of nodes 4->3->2->1->0
	head = new Node(0, NULL);
 
	for (int i=1; i<5; i++)
	{
		head_insert(head, i);
	}
	//Iterate through the list and display each value here:
	tmp = head;
	while (tmp != NULL)
	{
		cout << tmp->getData() << endl;
		tmp = tmp->getLink();
	}
	// Delete all nodes in the list before exiting the program.
	tmp = head;
	while (tmp != NULL)
	{
		NodePtr nodeToDelete = tmp;
		tmp = tmp->getLink();
		delete nodeToDelete;
	}

	cout << endl;
	return 0;
}
//This function inserts a new node onto the head of the list and is class-based 
void head_insert(NodePtr &head, int the_number)
{ 
	//creates a pointer called temp_ptr to type Node class 
	NodePtr temp_ptr;
	// Uses the overloaded constructor to set temp_ptr->link to head and set the data value to the_number here
	temp_ptr = new Node(the_number,head);
    //Makes the head pointer point at the new node (use temp_ptr) 
	head = temp_ptr;
}
Node::Node( ) : data(0), link(NULL)
{
	// deliberately empty
}
Node::Node(int value, Node *next) : data(value), link(next)
{
	// deliberately empty
}

// Accessor and Mutator methods follow
int Node::getData( ) const
{
	return data;
}
 
Node* Node::getLink( ) const
{
	return link;
}
 
void Node::setData(int value)
{
	data = value;
}
 
void Node::setLink(Node *next)
{
	link = next;
}