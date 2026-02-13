#include <iostream>
using namespace std;

// =====================================================
//               STACK IMPLEMENTATION (ARRAY)
// =====================================================
class Stack {
private:
    int top;
    int arr[100];     // static array stack
    int MAX;          // maximum size of stack

public:
    // Constructor
    Stack(int size = 100) {
        MAX = size;
        top = -1;
    }

    // -----------------------------------------------
    //               BASIC OPERATIONS
    // -----------------------------------------------

    // 1. PUSH operation
    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << x << "\n";
            return;
        }
        arr[++top] = x;
    }

    // 2. POP operation
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop.\n";
            return -1;
        }
        return arr[top--];
    }

    // 3. PEEK / TOP operation
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
            return -1;
        }
        return arr[top];
    }

    // 4. Check EMPTY
    bool isEmpty() {
        return (top == -1);
    }

    // 5. Check FULL
    bool isFull() {
        return (top == MAX - 1);
    }

    // 6. DISPLAY entire stack
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
            return;
        }

        cout << "Stack elements: ";
        for (int i = 0; i <= top; i++)
            cout << arr[i] << " ";
        cout << "\n";
    }
};

// =====================================================
//                     MAIN MENU
// =====================================================
int main() {
    Stack st;    // stack object
    int ch, val;

    while (true) {
        cout << "\n========== STACK MENU ==========\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Check Empty\n";
        cout << "6. Check Full\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter value to push: ";
                cin >> val;
                st.push(val);
                break;

            case 2:
                cout << "Popped: " << st.pop() << "\n";
                break;

            case 3:
                cout << "Top element: " << st.peek() << "\n";
                break;

            case 4:
                st.display();
                break;

            case 5:
                cout << (st.isEmpty() ? "Stack is EMPTY\n" : "Stack is NOT empty\n");
                break;

            case 6:
                cout << (st.isFull() ? "Stack is FULL\n" : "Stack is NOT full\n");
                break;

            case 7:
                return 0;

            default:
                cout << "Invalid choice!\n";
        }
    }
}
