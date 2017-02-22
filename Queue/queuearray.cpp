

#include <iostream>
using namespace std;

int QUEUE_ERROR = -99999;


int dequeue(int *q, int qcap, int *f, int *b) 
{ 
	 int r = QUEUE_ERROR; 
	 if (*f != *b) { 
		 r = q[(*f % qcap)]; 
		 *f = *f + 1; 
	 } 
	 return r;
}
 
int enqueue(int *q, int qcap, int *f, int *b, int v) { 
	int r = QUEUE_ERROR; 
	if (((*b + 1) % qcap) != (*f % qcap)) { 
		q[(*b % qcap)] = v; 
		*b = *b + 1; 
		r = *b; 
	} 
	return r; 
} 

int peek(int *q, int qcap, int *f, int *b) { 
	int r = QUEUE_ERROR; 
	if (*f != *b) { 
		r = q[(*f % qcap)]; 
	} 
	return r; 
} 
void show(int *q, int qcap, int *f, int *b) { 
	int c = 0; 
	cout << "<<"; 
	for (int i = *f; i < *b; i++) { 
		if (c++ > 0) cout << ", "; 
		cout << q[i % qcap]; 
	} 
	if (c == 0) cout << "empty";
	cout << "<<" << endl; 
} 

int main(int argc, const char * argv[])
{
    const int QUEUE_CAPACITY = 5;
    
    int queue[QUEUE_CAPACITY];
    int *front = new int; 
	int *back = new int; 
	*front = 0; 
    *back = 0; 

    
    show(queue, QUEUE_CAPACITY, front, back);
    
    enqueue(queue, QUEUE_CAPACITY, front, back, 42);
    
    show(queue, QUEUE_CAPACITY, front, back);

    int qr;
	int v;
    for (int i = 0; i < 8; i++) { 
		v = i * 2; 
		qr = enqueue(queue, QUEUE_CAPACITY, front, back, v); 
		if (qr == QUEUE_ERROR) { 
			cout << "Unable to enqueue value " << v << "; queue full." << endl; 
		} else { 
			show(queue, QUEUE_CAPACITY, front, back); 
		} 
	} 
 
	for (int i = 0; i < 9; i++) { 
		qr = dequeue(queue, QUEUE_CAPACITY, front, back); 
		if (qr == QUEUE_ERROR) { 
			cout << "Unable to dequeue value since queue is empty." << endl; 
		} else { 
			cout << "dequeued element = " << qr << endl; 
			show(queue, QUEUE_CAPACITY, front, back); 
		} 
	}

    return 0;
}
