#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

/*
Operations to support:
enqueue(x) — insert element at the rear
dequeue() — remove element from the front
front() — get element at the front
isEmpty() — check if queue is empty
isFull() — check if queue is full
(Optional) Dynamic resizing -------- to dooooooooooooooooooooooooooooooooooooooooooo

*/

// C++ Implementation — Queue using Circular Array

class Queue {
    int* arr;
    int capacity;
    int frontIdx;
    int rearIdx;
    int count;

public:
    // Constructor
    Queue(int size = 5) {
        capacity = size;
        arr = new int[capacity];
        frontIdx = 0;
        rearIdx = -1;
        count = 0;
    }

    // Enqueue → insert element at rear
    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot insert " << x << endl;
            return;
        }

        rearIdx = (rearIdx + 1) % capacity;
        arr[rearIdx] = x;
        count++;
        cout << "Enqueued: " << x << endl;
    }

    // Dequeue → remove element from front
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!" << endl;
            return;
        }

        cout << "Dequeued: " << arr[frontIdx] << endl;
        frontIdx = (frontIdx + 1) % capacity;
        count--;
    }

    // Get front element
    int front() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[frontIdx];
    }

    // Check if empty
    bool isEmpty() {
        return count == 0;
    }

    // Check if full
    bool isFull() {
        return count == capacity;
    }

    // Get current size
    int size() {
        return count;
    }

    // Destructor to free memory
    ~Queue() {
        delete[] arr;
    }
};

// -------------------
// Driver Code
// -------------------
int main() {
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60); // overflow

    cout << "Front element: " << q.front() << endl;

    q.dequeue();
    q.dequeue();

    q.enqueue(70);
    q.enqueue(80);

    cout << "Front element after ops: " << q.front() << endl;
    cout << "Current size: " << q.size() << endl;

    return 0;
}
