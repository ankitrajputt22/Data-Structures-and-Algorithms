/*
============================================================
LECTURE: STACK USING LINKED LIST
============================================================

1. Why Stack Using Linked List?
------------------------------------------------------------
In Array implementation:
• Size is fixed.
• Stack Overflow occurs when array is full.

In Linked List implementation:
• Size is dynamic.
• Stack grows until system memory is full.
• No need to define MAX size.

------------------------------------------------------------
2. Basic Idea
------------------------------------------------------------
We use a Linked List where:

• Each node contains:
    - data
    - pointer to next node

• The TOP of stack points to the head of the linked list.

------------------------------------------------------------
3. Stack Operations
------------------------------------------------------------

1. push(x)
   - Create new node.
   - Make new node point to current top.
   - Move top to new node.

2. pop()
   - Store top in temp.
   - Move top to next node.
   - Delete temp.

3. peek()
   - Return top->data.

4. isEmpty()
   - Check if top == NULL.

------------------------------------------------------------
4. Time Complexity
------------------------------------------------------------

push()  → O(1)
pop()   → O(1)
peek()  → O(1)

All operations are constant time.

------------------------------------------------------------
5. Memory Consideration
------------------------------------------------------------
Stack Overflow occurs only when:
System heap memory is exhausted.

============================================================
IMPLEMENTATION: STACK USING LINKED LIST
============================================================
*/

#include <iostream>
using namespace std;

/*=========================================================
Node Structure
=========================================================*/
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

/*=========================================================
Stack Class
=========================================================*/
class Stack {
private:
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    // Check if stack is empty
    bool isEmpty() {
        return (top == NULL);
    }

    // Push operation
    void push(int x) {

        Node* newNode = new Node(x);

        if (newNode == NULL) {
            cout << "Stack Overflow (Heap Full)!" << endl;
            return;
        }

        newNode->next = top;
        top = newNode;

        cout << x << " pushed into stack." << endl;
    }

    // Pop operation
    void pop() {

        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return;
        }

        Node* temp = top;
        cout << temp->data << " popped from stack." << endl;

        top = top->next;
        delete temp;
    }

    // Peek operation
    int peek() {

        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return -1;
        }

        return top->data;
    }

    // Display stack elements
    void display() {

        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }

        Node* temp = top;

        cout << "Stack elements (Top to Bottom): ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

/*=========================================================
MAIN FUNCTION
=========================================================
*/

int main() {

    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.display();

    cout << "Top element: " << s.peek() << endl;

    s.pop();
    s.pop();

    s.display();

    return 0;
}
