// Trejo_FinalExamProject.cpp : Defines the entry point for the console application.
//Name:Jaime Trejo
//Date 4/8/13
//Compiler:Microsoft Visual Studio 2012
//School:Wentworth Institute of Technology
//Class: Comp 201 Section 11
//Program: This program will have a private linked list class inside a class

#include "stdafx.h"
#include <iostream>
using namespace std;

class List
{
public:
	List(); // default constructor
	List(const List& aList);// copy constructor
	~List();// destructor
	void push(int addData);// adds into the list
	void pop(int deleteData);// removes from list
	void operator =(const List& aList); // overloaded assignment operator
	void printList();// print function
	bool empty() const;// returns true if the list is empty. Returns false otherwise
	int remove();
	//Precondition:The list is not empty
	//Returns the item at the head of the list and removes that item
	
private:

	class Node
	{
	public:
		Node *next;
		int data;
		
	};

	typedef class Node* NodePtr;

	NodePtr head;
	NodePtr current;
	NodePtr temp;
};



int _tmain(int argc, _TCHAR* argv[])
{
	List linkedList;

	cout << "Pushing values here: " << endl;
	cout << "------------------- " << endl;
	linkedList.push(1);
	linkedList.push(2);
	linkedList.push(3);
	linkedList.push(4);
	linkedList.push(5);
	linkedList.printList();
	cout << endl;

	cout << "Copy Constructor here: " << endl;
	cout << "--------------------- " << endl;
	List linkedList2(linkedList);
	linkedList2.printList();
	cout << endl;

	cout << "Assignment operator here: " << endl;
	cout << "------------------------ " << endl;
	List linkedList3;
	linkedList3 = linkedList2;
	linkedList3.printList();
	cout << endl;

	cout << "Popping values here: " << endl;
	cout << "------------------- " << endl;
	linkedList.pop(3);
	linkedList.printList(); 
	cout << endl;

	cout << "Copy Constructor here: " << endl;
	cout << "--------------------- " << endl;
	List linkedList4(linkedList);
	linkedList.printList();
	cout << endl;

	cout << "Popping values here: " << endl;
	cout << "------------------- " << endl;
	linkedList.pop(3);
	linkedList.printList(); 
	cout << endl;

	linkedList.pop(0);// will print out that 0 is not in the list
	linkedList.printList();
	cout << endl;

	linkedList.pop(1);//It will try to delete the head
	linkedList.printList();
	cout << endl;

	cout << "Assignment operator here: " << endl;
	cout << "------------------------ " << endl;
	List linkedList5;
	linkedList5 = linkedList;
	linkedList5.printList();
	cout << endl;
	return 0;
}
List::List()
{
	head = NULL;
	current = NULL;
	temp = NULL;
}

List::List(const List& aList)
{

		
	if(aList.head == NULL)
	{
		head = NULL;
	}
	else
	{
		NodePtr  temporary = aList.head;// temporary moves through the nodes from top to bottom of aList
		NodePtr end;// points to end of list

		end = new Node;
		end->data = temporary->data;
		head = end;
		//first node created and filled with data
		// new nodes are now added after this first node

		temporary = temporary->next;
		while(temporary !=NULL)
		{
			end->next = new Node;
			end = end->next;
			end->data = temporary->data;
			temporary = temporary->next;
		}
		end->next = NULL;
		}

}	


List::~List()
{
	char nextInLine;
	while(!empty())
	{
		nextInLine = remove();//remove calls delete
	}
	
}

void List::push(int addData)
{
	NodePtr n = new Node;
	n->next = NULL;
	n->data = addData;

	if(head !=NULL)
	{
		current = head;
		while(current->next !=NULL)
		{
			current = current->next;
		}

		current->next = n;
	}

	else
	{
		head = n;
	}

}
void List::pop(int deleteData)
{
	NodePtr delPtr = NULL;
	temp = head;
	current = head;

	while(current !=NULL && current->data != deleteData)
	{
		temp = current;
		current = current->next;
	}

	if(current == NULL)
	{
		cout << "You entered: " << deleteData << ", it is not in the list \n";
		delete delPtr;
	}

	else
	{
		delPtr = current;
		current = current->next;
		temp->next = current;
		if(delPtr == head)
		{
			head = head->next;
			temp = NULL;
		}

		delete delPtr;
		cout << "You entered: " << deleteData << ",The value " << deleteData << " was deleted \n" ;
	}


}

void List::printList()
{
	current = head;
	while(current !=NULL)
	{
		cout << current->data << endl;
		current = current->next;
	}
}

void List::operator =(const List& aList)
{	
	if (head == NULL)
	{
		char nextInLine;
		while(!empty())
		{
		nextInLine = remove();//remove calls delete
		}
		
		if(aList.head == NULL)
		{
			head = NULL;
		}
		else
		{
			NodePtr  temporary = aList.head;// temporary moves through the nodes from top to bottom of aList
			NodePtr end;// points to end of list

			end = new Node;
			end->data = temporary->data;
			head = end;
			//first node created and filled with data
			// new nodes are now added after this first node

			temporary = temporary->next;
			while(temporary !=NULL)
			{
				end->next = new Node;
				end = end->next;
				end->data = temporary->data;
				temporary = temporary->next;
			}
			end->next = NULL;
		}	
	}
}

bool List::empty() const
{
	return(head == NULL);
}
int List::remove()
{
	if(empty())
	{
		cout << "Error:Removing an item from an empty list \n";
		exit(1);
	}

	int result = head->data;
	NodePtr discard;
	
	discard = head;
	head = head->next;
	delete discard;

	return result;

}