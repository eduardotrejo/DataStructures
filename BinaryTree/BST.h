#ifndef BST_H_
#define BST_H_
#include <iostream>
using namespace std;

class BST
{
private:
	struct node{
		int key; // have an integer variable.
		node *left;
		node *right;
	};
	node *root; // node pointer root, refrence top of the tree.
	void addLeafPrivate(int key, node *Ptr){// worry about searching for the right location to find that for us
		if(root == NULL){
			root = CreateLeaf(key); // Creates a new leaf with the create value
		}else if(key < Ptr->key){	
			if(Ptr->left != NULL){
				addLeafPrivate(key, Ptr->left);// move down the left pointer
			}else{// if left pointer is not pointing to anything, then add to tree.
				Ptr->left = CreateLeaf(key);
			}
		}else if(key > Ptr->key){	
			if(Ptr->right != NULL){
				addLeafPrivate(key, Ptr->right);// move down the right pointer
			}else{// if right pointer is not pointing to anything, then add to tree.
				Ptr->right = CreateLeaf(key);
			}
		}else{
			cout << "The key " << key << " has already been added to the tree" << endl;
		}

	}

	void PrintInOrderPrivate(node *Ptr){// traverse the tree from lowest to highest value.
		if(root != NULL){
			if(Ptr->left != NULL){// if possibhle to go left
				PrintInOrderPrivate(Ptr->left);
			}
			cout << Ptr->key << " ";
			if(Ptr->right != NULL){// if possible to go right
				PrintInOrderPrivate(Ptr->right);
			}
		}else{	
			cout << "The tree is empty" << endl;
		}

	}
	node *CreateLeaf(int key)
	{
		node *n = new node; // n for new
		n->key = key;
		n->left = NULL;
		n->right = NULL;
	
		return n;
	}

	node *ReturnNodePrivate(int key, node *Ptr){ 
		if(Ptr != NULL){
			if(Ptr->key == key){
				// return Ptr to that current node thats the node that we want.
				return Ptr;
			}else{	
				// do some recurssion
				if(key < Ptr->key){
					// go left
					return ReturnNodePrivate(key, Ptr->left);
				}else{
					// go right
					return ReturnNodePrivate(key, Ptr->right);
				}
			}

		}else{
			return NULL;
		}
	}
public:
	BST(){ root = NULL;}	
	// call it from main, just worry about value.
	void addLeaf(int key){ addLeafPrivate(key, root);}
	void PrintInOrder() { PrintInOrderPrivate(root);}

	// find the node that contains that key value and return a pointer to that node
	node *ReturnNode(int key) { return ReturnNodePrivate(key, root);}

	int ReturnRootKey(){ 
		if(root != NULL){
			return root->key;
		}else{
			return -1000; 
		}
	}
	void PrintChildren(int key){ 
		// make it point to the return value of the return
		node *Ptr = ReturnNode(key);
		if(Ptr != NULL){
			cout << "Parent Node = " << Ptr->key << endl;

			Ptr->left == NULL ? // conditional operator if true goes to 1 if false goes to 2
			cout << "Left Child = NULL\n":
			cout << "Left Child = " << Ptr->left->key << endl;

			Ptr->right == NULL ? // conditional operator if true goes to 1 if false goes to 2
			cout << "Right Child = NULL\n":
			cout << "Right Child = " << Ptr->right->key << endl;

		}else{		
			cout << "Key " << key << " is not in the tree" << endl;
		}
	}
};
#endif