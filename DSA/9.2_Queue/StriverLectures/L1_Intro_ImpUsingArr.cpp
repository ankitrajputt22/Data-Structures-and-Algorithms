/*
============================================================
LECTURE: INTRODUCTION TO QUEUE
============================================================

1. What is a Queue?
------------------------------------------------------------
A Queue is a Linear Data Structure that follows the
FIFO principle.

FIFO = First In First Out

This means:
The element inserted first will be removed first.

------------------------------------------------------------
2. Real-Life Examples
------------------------------------------------------------
• People standing in a line
• Printer queue
• CPU scheduling
• Ticket booking system

------------------------------------------------------------
3. Basic Operations of Queue
------------------------------------------------------------

1. enqueue(x)
   Insert an element at the rear of the queue.

2. dequeue()
   Remove an element from the front of the queue.

3. front()
   Returns the front element without removing it.

4. isEmpty()
   Checks whether the queue is empty.

5. isFull()
   Checks whether the queue is full (for array implementation).

------------------------------------------------------------
4. Queue Representation Using Array
------------------------------------------------------------

We use:
• An array arr[]
• Two integer variables:
     front
     rear

Initially:
front = -1
rear  = -1

------------------------------------------------------------
5. Conditions
------------------------------------------------------------

Queue is Empty:
When front == -1 OR front > rear

Queue is Full (Linear Queue):
When rear == MAX - 1

------------------------------------------------------------
6. Important Limitation (Linear Queue)
------------------------------------------------------------

In linear queue using array:
Even if front moves forward after dequeues,
empty spaces at beginning cannot be reused.

This leads to memory wastage.

Solution:
Use Circular Queue (advanced topic).

------------------------------------------------------------
7. Time Complexity
------------------------------------------------------------

enqueue()  -> O(1)
dequeue()  -> O(1)
front()    -> O(1)

All operations are constant time.

============================================================
IMPLEMENTATION: QUEUE USING ARRAY (LINEAR QUEUE)
============================================================
*/

#include <iostream>
using namespace std;

#define MAX 5   // Maximum size of queue

class Queue {
private:
    int arr[MAX];
    int front;
    int rear;

public:
    // Constructor
    Queue() {
        front = -1;
        rear = -1;
    }

    // Check if queue is empty
    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    // Check if queue is full
    bool isFull() {
        return (rear == MAX - 1);
    }

    // Enqueue operation
    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot insert " << x << endl;
            return;
        }

        if (front == -1)
            front = 0;

        rear++;
        arr[rear] = x;

        cout << x << " inserted into queue." << endl;
    }

    // Dequeue operation
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Cannot remove." << endl;
            return;
        }

        cout << arr[front] << " removed from queue." << endl;
        front++;
    }

    // Get front element
    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        return arr[front];
    }

    // Display queue elements
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Queue elements (Front to Rear): ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

/*
============================================================
MAIN FUNCTION
============================================================
*/

int main() {

    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);   // Overflow case

    q.display();

    cout << "Front element is: " << q.getFront() << endl;

    q.dequeue();
    q.dequeue();

    q.display();

    return 0;
}
