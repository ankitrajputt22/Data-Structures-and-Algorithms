/*
============================================================
LECTURE: CIRCULAR QUEUE
============================================================

1. Why Circular Queue?
------------------------------------------------------------
In a Linear Queue (array implementation),
once rear reaches the last index (MAX-1),
we cannot insert new elements even if
there are empty spaces at the beginning.

This causes memory wastage.

Example:
MAX = 5

Insert 5 elements → rear = 4
Remove 2 elements → front = 2
Now index 0 and 1 are empty,
but rear = 4 (end of array),
so we cannot insert more elements.

Solution → Circular Queue

------------------------------------------------------------
2. What is Circular Queue?
------------------------------------------------------------
A Circular Queue connects the last index
back to the first index using circular logic.

It uses modulo operator (%) to wrap around.

------------------------------------------------------------
3. Circular Movement Formula
------------------------------------------------------------

Next index:
(index + 1) % MAX

This ensures:
If index == MAX-1
Next index becomes 0.

------------------------------------------------------------
4. Conditions
------------------------------------------------------------

Queue is Empty:
front == -1

Queue is Full:
(front == (rear + 1) % MAX)

------------------------------------------------------------
5. Time Complexity
------------------------------------------------------------

enqueue() → O(1)
dequeue() → O(1)
getFront() → O(1)

============================================================
IMPLEMENTATION: CIRCULAR QUEUE USING ARRAY
============================================================
*/

#include <iostream>
using namespace std;

#define MAX 5

class CircularQueue {
private:
    int arr[MAX];
    int front;
    int rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    // Check if queue is empty
    bool isEmpty() {
        return (front == -1);
    }

    // Check if queue is full
    bool isFull() {
        return ((rear + 1) % MAX == front);
    }

    // Enqueue operation
    void enqueue(int x) {

        if (isFull()) {
            cout << "Queue Overflow! Cannot insert " << x << endl;
            return;
        }

        // First element insertion
        if (isEmpty()) {
            front = rear = 0;
        }
        else {
            rear = (rear + 1) % MAX;
        }

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

        // If only one element
        if (front == rear) {
            front = rear = -1;
        }
        else {
            front = (front + 1) % MAX;
        }
    }

    // Get front element
    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        return arr[front];
    }

    // Display elements
    void display() {

        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Queue elements: ";

        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % MAX;
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

    CircularQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);   // May fill depending on MAX
    q.enqueue(60);   // Overflow

    q.display();

    q.dequeue();
    q.dequeue();

    q.display();

    q.enqueue(70);
    q.enqueue(80);

    q.display();

    cout << "Front element: " << q.getFront() << endl;

    return 0;
}
