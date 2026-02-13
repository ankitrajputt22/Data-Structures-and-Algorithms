#include <iostream>
using namespace std;

/*
🧠 Concept: Dynamic Array-Based Stack

We’ll implement a Stack using a dynamically allocated array.

✅ Core ideas:
Maintain:
int *arr → pointer to stack array
int capacity → current max size
int top → index of top element (-1 when empty)

When top + 1 == capacity (stack is full):
Allocate a new array of size = 2 × old capacity
Copy all old elements
Delete the old array

Continue normal push operations
*/

class Stack {
    int* arr;       // pointer to dynamic array
    int capacity;   // current capacity of array
    int top;        // index of top element

public:
    // Constructor
    Stack (int size = 2) {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }

    // Push function (with dynamic resizing)
    void push(int val) {
        if (top + 1 == capacity) {
            // Stack full → double capacity
            int newCapacity = 2 * capacity;
            int* newArr = new int[newCapacity];


            for (int i = 0; i < capacity; i++) newArr[i] = arr[i];
                
            delete[] arr;
            arr = newArr;
            capacity = newCapacity;

            cout << "🔁 Resized stack to capacity = " << capacity << endl;
        }

        arr[++top] = val;
        cout << "Pushed: " << val << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
            return;
        }
        cout << "Popped: " << arr[top--] << endl;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }

    int size() {
        return top + 1;
    }

    ~Stack() {
        delete[] arr;
    }
};

int main() {
    Stack st(2); // initial capacity = 2

    st.push(10);
    st.push(20);
    st.push(30);  // triggers resize
    st.push(40);
    st.push(50);  // triggers resize again

    cout << "Top element: " << st.peek() << endl;
    cout << "Stack size: " << st.size() << endl;

    st.pop();
    st.pop();
    st.pop();

    cout << "Top element after pops: " << st.peek() << endl;

    return 0;
}
