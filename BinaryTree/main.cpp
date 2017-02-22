#include <iostream>
#include "BST.h"
using namespace std;
 
int main()
{
	int TreeKeys[16] = {50, 76, 21, 4, 32, 64, 15, 52, 14, 100, 83, 2, 3, 70, 87, 80};

	BST myTree;

	cout << "Printing the tree in order\nBefore adding numbers\n";

	myTree.PrintInOrder();
	cout << endl;
	for(int i = 0; i < 16; i++){
		myTree.addLeaf(TreeKeys[i]);
	}
	cout << "Printing the tree in order\nAfter adding numbers\n";

	myTree.PrintInOrder();
	cout << endl;

	//myTree.PrintChildren(myTree.ReturnRootKey()); // root is 50, left child 21, right child 76

	for(int i = 0; i < 16; i++){
		myTree.PrintChildren(TreeKeys[i]);// prints all the cildren
		cout << endl;
	}
	return 0;
}

