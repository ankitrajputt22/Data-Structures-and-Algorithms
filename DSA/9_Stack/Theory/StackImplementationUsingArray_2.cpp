#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

class Stack {
private:
    int top;
    int arr[100];
    int maxSize;
    int currSize;

public:
    Stack(int size = 100) {
        top = -1;
        maxSize = size;
        currSize = 0;
    }

    bool isFull() {
        if (top == maxSize - 1) {
            return true;
        }

        return false;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(int val) {
        if (isFull()) {
            cout << "Stack OverFlow!" << endl;
            return;
        }

        arr[++top] = val;
        currSize++;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack UnderFlow!" << endl;
            return;
        }

        top--;
        currSize--;
    }

    int pop2() {
        if (top == -1) {
            cout << "Stack UnderFlow!" << endl;
            return -1;
        }

        return arr[top--];
    }

    int peek() {
        if (isEmpty()) {
            cout << "Empty Stack" << endl;
            return -1;
        }
        return arr[top];
    }

    int size() {
        return top+1;      // return size
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is Empty" << endl;
            return;
        }

        int ind = top;
        cout << "Stack left(top) to right(bottom) :-" << endl;
        while (ind != -1) {
            cout << arr[ind--] << " ";
        }

        cout << endl;
    }
    

};

int main() {
    newline2;

    Stack s;
    s.push(8);
    s.push(9);
    s.push(877);

    s.display();
    cout << "Top element: " << s.peek() << endl;
    s.pop();
    cout << "Popped Element: " << s.pop2() << endl;
    cout << "Top element: " << s.peek() << endl;



    

    newline2;
    return 0;
}