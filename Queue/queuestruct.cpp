
#include <iostream>

using namespace std;

int QUEUE_ERROR = -99999;

struct Node {
    int value;
    Node * next;
};

struct Queue {
    Node * front;
    Node * back;
    
};

void enqueue(Queue &q, int v) {
    Node * back = q.back;
    Node * n = new Node();
    n->value = v;
    n->next = 0;
    if (back == 0) {
        q.front = n;
        q.back = n;
    } else {
        q.back->next = n;
        q.back = n;
    }
}

int dequeue(Queue &q) {
    int r = QUEUE_ERROR;
    if (q.front != 0) {
        r = q.front->value;
        Node * tmp = q.front;
        q.front = q.front->next;
        delete tmp;
    }
    return r;
}

int peek(Queue q) {
    int r = QUEUE_ERROR;
    if (q.front != 0) {
        r = q.front->value;
    }
    return r;
}

void show(Queue q) {
    Node * n = q.front;
    int c = 0;
    cout << "{{";
    if (n == 0) {
        cout << "empty";
    } else {
        while (n != 0) {
            if (c++ > 0) cout << ", ";
            cout << n->value;
            n = n->next;
        }
    }
    cout << "}}" << endl;
}

int main(int argc, const char * argv[])
{
    Queue queue = Queue();
    queue.front = 0;
    queue.back = 0;
    
    show(queue);
    
    enqueue(queue, 42);
    show(queue);

    enqueue(queue, 43);
    show(queue);
    
    cout << "peek(): " << peek(queue) << endl;
    show(queue);
    
    cout << "dequeue(): should be 42 = " << dequeue(queue) << endl;
    show(queue);

    cout << "dequeue(): should be 43 = " << dequeue(queue) << endl;
    show(queue);

    cout << "dequeue(): should be error: " << dequeue(queue) << endl;
    show(queue);

    return 0;
}
