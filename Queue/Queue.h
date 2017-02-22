/*
 Developer: Trejo, Eduardo
 ID: 6787
 Course: CST 238
 Assignment: hw07
 Date: 2014-04-07
 Abstract: This part of the program contains the Queue class. It contains the functions: show, enqueue, peek, dequeue, clear, and getCount. 
		   It also sets up the default constructor, the Node *front and Node *back pointer.
 */
#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>
#include "Node.h"
using namespace std;

class Queue
{
private:
	// Hold the current size of the Queue.
	int count;
	// Front pointer.
	Node *front;
	// Back pointer.
	Node *back;
public:
	// Default constructer.
	Queue(){ front = NULL; back = NULL;}
	// Constructs default Queue with the front element.
	Queue(Node *f){ f = NULL;}
	// Returns the current size of the Queue.
	int getCount(){ return count;}	
	// Prints out the elements of the Queue.
	void show(){
		Node *f = front;
		int c = 0;
		count = 0;
		cout << "{{";
		if(f == 0){
			cout << "empty";
		}else{
			while(f != 0){
				if(c++ > 0){
					cout << ", ";
				}
				cout << f->value;
				f = f->next;
				count++;
			}
		}
		cout << "}}" << endl;
	}
	// Puts a value and the back of the Queue.
	void enqueue(int v){	
		Node *n = new Node;
		n->value = v;
		n->next = NULL;
		if(back == NULL){
			 front = n;
			 back = n;
		}else{
			 back->next = n;
			 back = n;
		}
	}
	// Returns the front value of the queue, if no front returns -99999.
	int peek(){
		int r = -99999;
		if(front != 0){
			// Gets to read in the front value.
			r = front->value;
		}
		return r;
	}
	// Returns the front value of the queue and removes the front, if no front returns -99999.
	int dequeue(){
		int r = -99999;
		if(front != 0){
			r = front->value;
			// Create a tmp pointer to store the front value and delete it.
			Node *tmp = front;
			// Sets up the next front, connects the nodes.
			front = front->next;
			delete tmp;
		}
		return r;
	}
	// Clears and reclaims all Node elements of the queue.
	void clear(){
		Node *del = front;
		// Traverse the stack and delete the node one by one from the front.
		while(del != NULL){
			// Take out the front node.
			front = front->next;
			delete del;
			// Update the front node.
			del = front;
		}
		// Reset the front.
		front = NULL;
	}
};
#endif