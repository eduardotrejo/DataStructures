/*
 Developer: Trejo, Eduardo
 ID: 6787
 Course: CST 238
 Assignment: hw09
 Date: 2014-05-05
 Abstract: This part of the program includes Node.h. It creates a Node *root pointer, Node *CreateLeaf function which is called
		   to add a new element. Other functions that are included are a bool exists, inorder, preorder, and postorder functions.
 */
#ifndef _TREE_H_
#define _TREE_H_

#include <iostream>
#include "Node.h"
#include <string>
using namespace std;

class Tree
{
private:
	// Node pointer root, refrence top of the tree.
	Node *root; 
	// Used to create a leaf node for the add function.
	Node *CreateLeaf(int value)
	{
		// n for new.
		Node *n = new Node; 
		n->value = value;
		n->left = NULL;
		n->right = NULL;
	
		return n;
	}
	/* Will start at the root node (the first node added) and create a leaf node for the added element that is to the 
	   left of the root if the new int is less than the root value, and to the right of the root if the new int 
	   is greater than or equal to the root value.*/
	void add(int i, Node *n){
		if(root == NULL){
			// Creates a new leaf with the create value.
			root = CreateLeaf(i); 
		}else if(i < n->value){	
			if(n->left != NULL){
				// Move down the left pointer.
				add(i, n->left);
			// If left pointer is not pointing to anything, then add to tree.
			}else{
				n->left = CreateLeaf(i);
			}
		}else if(i > n->value){	
			if(n->right != NULL){
				// Move down the right pointer.
				add(i, n->right);
			// If right pointer is not pointing to anything, then add to tree.
			}else{
				n->right = CreateLeaf(i);
			}
		}else{
			cout << "The key " << i << " has already been added to the tree" << endl;
		}

	}
	/* Print all the items in the tree to which root points. The items in the left subtree are printed first, followed 
       by the item in the root node, followed by the items in the right subtree. Traverse the tree from lowest
	   to highest value.*/
	string inorder(Node *n){
		string r;
		if(root != NULL){
			// If possibhle to go left.
			if(n->left != NULL){
				// Print items in left subtree.
				r = inorder(n->left);
			}
			// Print the root item.
			cout << n->value << " ";
			// If possible to go right.
			if(n->right != NULL){
				// Print items in right subtree.
				r = inorder(n->right);
			}
		}else{	
			r = "The tree is empty";
		}
		return r;
	}
	/* Print all the items in the tree to which root points. The item in the root is printed first, followed by the
       items in the left subtree and then the items in the right subtree.*/
	string preorder(Node *n){
		string r;
		if(root != NULL){
			// Print the root item.
			cout << n->value << " "; 
			// If possibhle to go left.
			if(n->left != NULL){
				// Print items in left subtree.
				r = preorder(n->left);
			}
			// If possible to go right.
			if(n->right != NULL){
				// Print items in right subtree.
				r = preorder(n->right);
			}			
		}else{	
			r = "The tree is empty";
		}
		return r;
	}
	/* Print all the items in the tree to which root points. The items in the left subtree are printed first, followed 
	   by the items in the right subtree and then the item in the root node.*/
	string postorder(Node *n){
		string r;
		if(root != NULL){
			// If possibhle to go left.
			if(n->left != NULL){
				// Print items in left subtree.
				r = postorder(n->left);
			}
			// If possible to go right.
			if(n->right != NULL){
				// Print items in right subtree.
				r = postorder(n->right);
			}
			// Print the root item.
			cout << n->value << " ";
		}else{	
			r = "The tree is empty";
		}
		return r;
	}
	/* Will return true if the integer x exists in the binary tree, and returns false if integer x
	   does NOT exist as a node value in the binary tree.*/
	bool exists(int x, Node *n){
		bool found = 0;
		n = root;	
		while(n != NULL && !found){
			// Root is x.
			if(n->value == x){
				// Set to found.
				found = 1;
			// Descend left.
			}else if(x < n->value){
				n = n->left;
			// Descend right.
			}else if(n->value < x){
				n = n->right;
			}else{	
				// Set to found.
				found = 1;
			}
		}	
		return found;
	}
public:
	// Default constructor.
	Tree(){ root = NULL;}	
	// Add function. Creates a leaf node for the new added element.
	void add(int i){ add(i, root);}
	// Prints out the elements inorder.
	string inorder() { return inorder(root);}
	// Prints out the elements preorder.
	string preorder() { return preorder(root);}
	// Prints out the elements postorder.
	string postorder() { return postorder(root);}
	// Checks if the interger x exists in the binary tree.
	bool exists(int x){ return exists(x, root);}
};
#endif