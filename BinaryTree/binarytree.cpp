/*
 Developer: Trejo, Eduardo
 Date: 2014-05-05
 Abstract: This program consists of a Node.h and Tree.h part of the program includes the Tree.h file, that runs all
		   the functions for the program. It creates a new Tree pointer.
 */
#include <iostream>
#include "Tree.h"
using namespace std;

int main(){

    Tree * tree = new Tree();
	
	// Add a new element.
    tree->add(42);
    tree->add(3);
    tree->add(1);
    tree->add(44);
    tree->add(43);
    tree->add(2);

	// Print out what the tree would look like.
    cout << "binary tree after adds:" << endl << endl;
    cout << "          (42)" << endl;
    cout << "         /    \\" << endl;
    cout << "      (3)      (44)" << endl;
    cout << "     /         /" << endl;
    cout << "   (1)      (43)" << endl;
    cout << "      \\" << endl;
    cout << "       (2)" << endl << endl;

	// If I wouldn't put a cout infront of the function calls, the result would print out first.
    cout << "inorder traversal: "; cout << tree->inorder() << endl;
    cout << "preorder traversal: "; cout << tree->preorder() << endl;
    cout << "postorder traversal: "; cout << tree->postorder() << endl << endl;;

	// Check if the elements exist.
    cout << "exists? 4 ?-> " << tree->exists(4) << endl;
    cout << "exists? 43 ?-> " << tree->exists(43) << endl;
    cout << "exists? 6 ?-> " << tree->exists(6) << endl;
    cout << "exists? 44 ?-> " << tree->exists(44) << endl;
    cout << "exists? 1 ?-> " << tree->exists(1) << endl;
    cout << "exists? 3 ?-> " << tree->exists(3) << endl;
    cout << "exists? 42 ?-> " << tree->exists(42) << endl;
    cout << "exists? 2 ?-> " << tree->exists(2) << endl;
    cout << "exists? 434 ?-> " << tree->exists(434) << endl << endl;

    return 0;
}
