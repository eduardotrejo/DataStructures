#ifndef LIST_H
#define LIST_H
class List
{
private:
	typedef struct node
	{
		int data; // stores data
		node* next; // create a node pointer, will point to next node in the list
	}* nodePtr;
	//typedef struct node* nodePtr; // allows me to type in nodePtr i.e same thing as typing struct node*

	nodePtr head;
	nodePtr curr;
	nodePtr temp;
public:
	// this is where the functions go, functions will access the private data. Manipulate list/data the way we want. 
	//contructor set default values for head, curr, and temp.
	List();
	void addNode(int addData); // add a node and place a certain value inside it.
	void deleteNode(int delData); // go through list until it matches the data and deletes that node.
	void printList(); 
};

#endif