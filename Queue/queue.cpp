/*
 Developer: Trejo, Eduardo
 Date: 2014-04-07
 Abstract: This program consist of a Class Implementation of a Queue. It contains a Node.h and a Queue.h class. All functions available in Queue.h.
 */
#include <iostream>
#include "Queue.h"
using namespace std;

int main(int argc, const char * argv[]){
    Queue *q = new Queue();

	// Prints out the elements of the Queue.
    q->show();
	// Returns the current size of the Queue.
	cout << "Size of queue: " << q->getCount() << endl; 
	// Puts a value and the back of the Queue.
	q->enqueue(43);

    q->show();
	cout << "Size of queue: " << q->getCount() << endl; 
	// Returns the front value of the queue
    cout << "peek(): " << q->peek() << endl;

    q->show();

    for(int i = 0; i < 10; i++){
        q->enqueue(i * 2);
        q->show();
		cout << "Size of queue: " << q->getCount() << endl; 
    }

    int qr;
    for(int i = 0; i < 12; i++){
		// Returns the front value of the queue and removes the front.
        qr = q->dequeue();
        if(qr == -99999){
            cout << "Queue is empty." << endl;
        }else{
            cout << "dequeued: " << qr << endl; 
        }
        q->show();
		cout << "Size of queue: " << q->getCount() << endl; 
    }
	
	// Clears and reclaims all Node elements of the queue.
	cout << "**Clear Function Test**" << endl;
	q->clear();

	q->show();
	cout << "Size of queue: " << q->getCount() << endl; 
    return 0;
}
