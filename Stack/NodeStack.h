/*
 Developer: Trejo, Eduardo
 ID: 6787
 Course: CST 238
 Assignment: hw06
 Date: 2014-03-30
 Abstract: This part of the program contains the NodeStack class. It contains the default constructor, contructor that initializes the top element,
		   a show function, a peek function, a pop function, a getCount function, and a clear function. 
 */
#ifndef NODESTACK_H_
#define NODESTACK_H_

#include <iostream>
#include <climits> // Used for INT_MIN.
#include "Node.h"
using namespace std;

class NodeStack
{
private:
	int count;
	Node *top;
public:
	// Default constructer.
	NodeStack(){ top = NULL;}
	// Constructs default NodeList with top element.
	NodeStack(Node *t){ t = NULL;}
	// Holds the current size of the NodeStack.
	int getCount(){ return count;}
	// Prints out the elements of the stack.
	void show(){ 
		count = 0;
		cout << "[[";
		if(top == 0){
			cout << "<empty>";
		}else{
			Node * n = top;
			int c = 0;
			while(n != 0){
				if(c++ > 0){
					cout << ", ";
				}
				cout << n->value;
				n = n->next;
				count++;
			}
		}
		cout << "]]" << endl;
	}
	// Returns the top value of the stack; if no top (meaning no elements in stack), returns INT_MIN.
	int peek(){
		int r = INT_MIN;
		if(top != 0){
			r = top->value;
		}
		return r; 
	}
	// Pushes a value onto the stack.
	void push(int value){
		Node *n = new Node;
		n->value = value;
		// Top is my top. Need to make a next.
		// If there isn't anything in stack.
		if(top == NULL){
			//top of stack
			top = n;
			// Then point to NULL
			top->next = NULL;
		}
		// If the stack does contain something.
		else{	
			// Connected new value to the top of stack, update it to point to new top.
			n->next = top;
			top = n;
		}
	}
	// Returns the top value of the stack and pops off the top value; if no top, returns INT_MIN 
	int pop(){
		int r = INT_MIN;
		if(top != 0){
			// Result on top.
			r = top->value;
			// Grab the top.
			Node * tmp = top;
			top = top->next;
			delete tmp;
		}
		return r;
	}
	// Clears and reclaims all Node elements of the stack.
	void clear(){
		Node *del = top;
		// Traverse the stack and delete the node one by one from the top.
		while(del != NULL){
			// Take out the top node.
			top = top->next;
			delete del;
			// Update the top node.
			del = top;
		}
		// Reset the top.
		top = NULL;
	}
};
#endif