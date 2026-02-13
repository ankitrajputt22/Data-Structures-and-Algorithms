#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

class StackUsingArray {
    int* arr;       
    int capacity;  
    int top;      

public:
    StackUsingArray (int size) {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }

    void push (int val) {
        if (top + 1 == capacity) {
            int newCapacity = 2 * capacity;
            int* newArr = new int[newCapacity];


            for (int i = 0; i < capacity; i++) newArr[i] = arr[i];
                
            delete[] arr;
            arr = newArr;
            capacity = newCapacity;

        }

        arr[++top] = val;
        cout << "Pushed: " << val << endl;
    }
};

int main() {
    
    return 0;
}