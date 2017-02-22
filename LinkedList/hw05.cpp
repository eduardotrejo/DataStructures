/*
 Developer: Trejo, Eduardo
 ID: 6787
 Course: CST 238
 Assignment: hw05
 Date: 2014-03-23
 Abstract: This program constructs a linked list using the method of a C++ Class implementation of List.
		   Uses Node.h and NodeList.h.
 */
#include "NodeList.h"
using namespace std;

int main(int argc, const char * argv[])
{
    NodeList nodeList;
    Node *n = new Node;
	// Use to modify the the value stored in the list.
    n->setValue(14);
	// Set the base of the NodeList.
    nodeList.setBase(n);
	// Prints out the elements of the list.
    nodeList.show();
	// Prints out the size of the list.
	nodeList.length();

	// Adds a value to beginning of the list and returns the pointer to the corresponding Node.
    nodeList.add(42);
    nodeList.show();
	nodeList.length();

	// Retrieve value for this node.
    cout << "nodeList.get(-2) = " << nodeList.get(-2)->getValue() << endl;
    cout << "nodeList.get(2222) = " << nodeList.get(2222)->getValue() << endl;

    for(int i = 0; i < 10; i++){
        nodeList.add(i * 4);
    }
    nodeList.show();
	nodeList.length();

	// Couldn't get it to work would get a runtime error.
	// Inserts a value at index and returns the pointer to the corresponding Node.
    //nodeList.insert(999, 99999999);
    //nodeList.show();

	// Removes element at index and returns the pointer to the removed Node.
    nodeList.remove(9);
    nodeList.show();
	nodeList.length();

	// Clears and reclaims all Node elements.
    nodeList.clear();
    nodeList.show();
	nodeList.length();
    return 0;
}