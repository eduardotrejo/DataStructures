#include <iostream>
using namespace std;

struct Node {
    int value;
    Node * next; //= 0
};

struct Stack {
    Node * top; // = 0
};

void push(Stack * stack, int value) {
    Node *node = new Node;
    node->value = value;
    if (stack->top == 0) {
        node->next = 0;
        stack->top = node;
    } else {
        node->next = stack->top;
        stack->top = node;
    }
}
int pop(Stack * stack){
	int r = -999;
    if (stack->top != 0) {
		// result on topo
        r = stack->top->value;
		// grab the top
		Node * tmp = stack->top;
		stack->top = stack->top->next;
		delete tmp;
    }
    return r;
}
void show(Stack * stack) {
    cout << "[[";
    if (stack->top == 0) {
        cout << "<empty>";
    } else {
        Node * n = stack->top;
        int c = 0;
        while (n != 0) {
            if (c++ > 0){
				cout << ", ";
			}
            cout << n->value;
            n = n->next;
        }
    }
    cout << "]]" << endl;
}
int peek(Stack * stack) {
    int r = -999;
    if (stack->top != 0) {
        r = stack->top->value;
    }
    return r;
}
int main(int argc, const char * argv[])
{
    Stack * stack = new Stack;
	stack->top = 0;
    push(stack, 2); 
    show(stack);
    push(stack, 4);
    show(stack);
    push(stack, 6);
    show(stack);
    cout << "peek : (should be 6) => " << peek(stack) << endl;
	pop(stack);
	show(stack);
    return 0;
}
