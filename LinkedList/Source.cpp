
#include <iostream>
#include "list.h"
using namespace std;

int main(int argc, const char* argv[])
{
	List Eduardo;

	Eduardo.addNode(3);
	Eduardo.addNode(5);
	Eduardo.addNode(7);
	Eduardo.printList();

	Eduardo.deleteNode(3);
	Eduardo.printList();
	return 0;
}
