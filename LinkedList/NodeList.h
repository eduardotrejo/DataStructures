/*
 Developer: Trejo, Eduardo
 Date: 2014-03-23
 Abstract: This program constructs a NodeList class by using the Node class.
 */
#ifndef NODELIST_H_
#define NODELIST_H_

#include "Node.h"
class NodeList
{
private:
	Node *base;
	int size;
public:
	// Prints out the size of the list.
	int length(){ cout << "Size: " << size << endl; return size;}
	// Default constructer.
	NodeList(){ base = NULL;}
	// Constructs default NodeList with base element.
	NodeList(Node *b){ b = NULL;}
	// Set the base of the NodeList.
	void setBase(Node *b){ base = b;}
	// Prints out the elements of the list.
	void show(){ 
		size = 0;
		Node *temp = base;
		// If base == 0, the list is empty.
		if(temp == NULL){
			cout << "(<empty>)" << endl;
		}
		else{
			cout << "(";
			int c = 0;
			while(temp != NULL)
			{
				if(c++ > 0) {
					cout << ", ";
				}
				cout << temp->value;
				temp = temp->next;
				size++;
			}
			cout << ")" << endl;
		}
	}
	// Adds a value to beginning of the list and returns the pointer to the corresponding Node.
	Node * add(int value){
	
		Node *temp = new Node;
		// What the node is going to hold.
		temp->setValue(value);
		temp->setNext(base);
		base = temp;
		return base;
	}
	// Returns the pointer to the Node at index.	 
	Node * get(int index){
		Node *rn = base;
		// Element count.
		int c = 0;
		// If index <= 0, return base.
        if((rn->next != 0) && (c++ < index)){
			  rn = rn->next;
		// If index >= element count, return last Node.
	    }else if((rn->next != 0) && (index > c++)){
			rn = rn->next;
		}
	    return rn;
	}
	// Inserts a value at index and returns the pointer to the corresponding Node.
	// If index > element count, use last index. If index < 0, use index = 0.
	Node * insert(int value, int index){
	}	
	// Removes element at index and returns the pointer to the removed Node.
	Node * remove(int index){
		Node *temp1 = base;
		int i;
		// If index <= 0, remove base.
		if(index <= 0){
			base = temp1->next;
			delete base;
		}
		// If index >= element count, remove last Node.
		else{
			for(i = 0; i < index - 1; i++){
				temp1 = temp1->next;
			}
			Node *temp2 = temp1->next;
		    temp1->next = temp2->next;
		    delete temp2;
		}		
		return temp1;
	}
	// Clears and reclaims all Node elements.
	void clear(){
		Node *del = base;
		// Traverse the list and delete the node one by one from the base.
		while(del != NULL){
			// Take out the head node.
			base = base->next;
			delete del;
			// Update the base node.
			del = base;
		}
		// Reset the base.
		base = NULL;
	}
};
#endif
