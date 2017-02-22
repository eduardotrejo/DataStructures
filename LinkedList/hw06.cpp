/*
 Developer: Trejo, Eduardo
 ID: 6787
 Course: CST 238
 Assignment: hw06
 Date: 2014-03-30
 Abstract: This program consist of a Class Implementation of a Stack. It contains a Node.h and a NodeStack.h class respectively. All functions available in NodeStack.h.
 */
#include <iostream>
#include "NodeStack.h"
using namespace std;

int main(int argc, const char * argv[])
{
	// Create an object of NodeStack.
    NodeStack stack;
	// Prints out the elements of the stack.
    stack.show();
	// Returns the top value of the stack.
    cout << "peek: " << stack.peek() << endl;
	// Pushes a value onto the stack.
    stack.push(42);
    stack.show();
    cout << "peek: " << stack.peek() << endl;
    stack.push(1);
    stack.show();
    cout << "peek: " << stack.peek() << endl;
	// Returns the top value of the stack and pops off the top value.
    cout << "pop: " << stack.pop() << endl;
    stack.show();
    for(int i = 0; i < 5; i++){
        stack.push(i * 2);
        stack.show();
    }
	// Holds the current size of the NodeStack.
    cout << "count: " << stack.getCount() << endl;
    for(int i = 0; i < 5; i++){
        cout << "pop: " << stack.pop() << endl;
        stack.show();
        cout << "count: " << stack.getCount() << endl;
    }
    stack.pop();
    stack.show();
    return 0;
}