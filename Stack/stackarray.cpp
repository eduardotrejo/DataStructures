
// stack as static array

#include <iostream>
using namespace std;

void push(int * stack, int &top, int value) {
    stack[++top] = value;
}

void show(int * stack, int top) {
    
    cout << "[[";
    
    for (int i = 0; i <= top; i++) {
        if (i > 0) cout << ", ";
        cout << stack[i];
    }
    
    if (top < 0) cout << "<empty>";
    
    cout << "]]" << endl;
    
}

int peek(int * stack, int top) {
    return stack[top];
}

int main(int argc, const char * argv[])
{
    int stack[1024];
    int top = -1;
    
    show(stack, top);
    push(stack, top, 2);
    cout << "peek (should be 2) => " << peek(stack,top) << endl;
    push(stack, top, 4);
    cout << "peek (should be 4) => " << peek(stack,top) << endl;
    show(stack, top);
    
    
    
    
    return 0;
}









