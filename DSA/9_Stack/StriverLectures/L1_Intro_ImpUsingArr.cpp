/*
============================================================
LECTURE: INTRODUCTION TO STACK
============================================================

1. What is a Stack?
------------------------------------------------------------
A Stack is a Linear Data Structure that follows the
LIFO principle.

LIFO = Last In First Out

This means:
The element inserted last will be removed first.

------------------------------------------------------------
2. Real-Life Examples
------------------------------------------------------------
• Stack of plates
• Undo/Redo functionality
• Browser Back button
• Function calls (Call Stack)

------------------------------------------------------------
3. Basic Operations of Stack
------------------------------------------------------------

1. push(x)
   Insert an element into the stack.

2. pop()
   Remove the top element from the stack.

3. peek() / top()
   Returns the top element without removing it.

4. isEmpty()
   Checks if stack is empty.

5. isFull()
   Checks if stack is full (for array implementation).

------------------------------------------------------------
4. Stack Representation
------------------------------------------------------------

Stack can be implemented using:
• Array
• Linked List
• STL stack (C++)

In this lecture, we implement using ARRAY.

------------------------------------------------------------
5. Array Implementation Concept
------------------------------------------------------------

We use:
• An array arr[]
• An integer variable top

Initially:
top = -1

Why -1?
Because when stack is empty, there is no element.
After first push, top becomes 0.

------------------------------------------------------------
6. Conditions
------------------------------------------------------------

Stack Overflow:
Occurs when we try to push into a full stack.

Stack Underflow:
Occurs when we try to pop from an empty stack.

------------------------------------------------------------
7. Time Complexity
------------------------------------------------------------

push()  -> O(1)
pop()   -> O(1)
peek()  -> O(1)

All operations are constant time.

============================================================
IMPLEMENTATION: STACK USING ARRAY
============================================================
*/

#include <iostream>
using namespace std;

#define MAX 5   // Maximum size of stack

class Stack {
private:
    int arr[MAX];
    int top;

public:
    // Constructor
    Stack() {
        top = -1;
    }

    // Check if stack is empty
    bool isEmpty() {
        return (top == -1);
    }

    // Check if stack is full
    bool isFull() {
        return (top == MAX - 1);
    }

    // Push operation
    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << x << endl;
            return;
        }

        top++;
        arr[top] = x;
        cout << x << " pushed into stack." << endl;
    }

    // Pop operation
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop." << endl;
            return;
        }

        cout << arr[top] << " popped from stack." << endl;
        top--;
    }

    // Peek operation
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return -1;
        }

        return arr[top];
    }

    // Display stack elements
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }

        cout << "Stack elements (Top to Bottom): ";
        for (int i = top; i >= 0; i--) {
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

    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);  // Overflow case

    s.display();

    cout << "Top element is: " << s.peek() << endl;

    s.pop();
    s.pop();

    s.display();

    return 0;
}
