
#include <iostream>
#include "list.h"
using namespace std;

// constructor
List::List()
{
	head = NULL;
	curr = NULL;
	temp = NULL;
}
void List::addNode(int addData)
{
	// null pointer point to new node.
	nodePtr n = new node;
	// find the node n is pointing to access its next element and make it point to nothing.
	n->next = NULL;
	// what the node is going to hold
	n->data = addData;

	// if head is pointing to an object. At least one lement in the list.
	if(head != NULL)
	{
		// take current pointer and make it point to the same thing head is pointing to.
		curr = head;
		// to check if last node in the list.Advances until it reaches NULL then exit.
		while(curr->next != NULL)
		{
			curr = curr->next;
		}
		// points to new node that we filled with data. 
		curr->next = n;

	}
	// if not then its infront of the list. Make n the new node, the front.
	else
	{
		head = n;
	}
}

void List::deleteNode(int delData)
{
	// deletion pointer
	nodePtr delPtr = NULL;
	// make temp and curr point to same thign head is pointing, beginning of the list.
	temp = head;
	curr = head;
	// check to see if current node is the one we want to delete or else advance current pointer, have temp current pointer trail the current one step behind to patch up list if we delete 
	// somewhere in the middle.
	// if traversed then we dont have advance anymore and exit. If it is then exit while and delete that node. 
	// Will traverse.
	while(curr != NULL && curr->data != delData) 
	{
		temp = curr;
		curr = curr->next;
	}
	// means we passed the list and we didnt find the value we were looking for.
	if(curr == NULL)
	{
		cout << delData << " was not in the list\n";
		// not take up more memory if program continues to run.
		delete delPtr;
	}
	else
	{
		// pointing to node we want to delete.
		delPtr = curr;
		// path hole in list.
		// advances curr, we dont want curr to be involved in the deletion process.
		curr = curr->next;
		// pointing to node that we want to connect, since we have been trailing.
		temp->next = curr;
		// want to advance the head
		if(delPtr == head)
		{
			head = head->next;
			temp = NULL;
		}
		delete delPtr;
		cout << "The value " << delData << " was deleted" << endl;
	}

}
void List::printList()
{
	// make it point to front of the list
	curr = head;
	while(curr != NULL)
	{
		// output data the curr is poiting to and advance
		cout << curr->data << endl;
		curr = curr->next;
	}

}
