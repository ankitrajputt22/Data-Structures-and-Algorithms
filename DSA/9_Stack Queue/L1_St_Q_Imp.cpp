//L1. Introduction to Stack and Queue | Implementation using Data Structures................................
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


#include <iostream>
using namespace std;
#define maxSize 100
#define newline cout << "\n\n\n"

class StackImpUsingArr {
    private:
        int arr[maxSize];
        int topIndex;
    
    public:
        // Constructor
        StackImpUsingArr() {
            topIndex = -1;  // Initialize empty stack
        }
    
        // Push operation
        void push(int value) {
            if (topIndex >= maxSize - 1) {
                cout << "Stack Overflow\n";
                return;
            }
            topIndex = topIndex + 1;
            arr[topIndex] = value;
        }
    
        // Pop operation
        int pop() {
            if (isEmpty()) {
                cout << "Stack Underflow\n";
                return -1;  // Return error value
            }
            return arr[topIndex--];
        }
    
        // Peek operation
        int top() {
            if (isEmpty()) {
                cout << "Stack is empty\n";
                return -1;   // Return error value
            }
            return arr[topIndex];
        }
    
        // Check if stack is empty
        bool isEmpty() {
            return topIndex == -1;
        }
    
        // Check if stack is full
        bool isFull() {
            return topIndex == maxSize - 1;
        }
    
        // Get stack size
        int size() {
            return topIndex + 1;
        }
    
        // Display stack elements
        void display() {
            if (isEmpty()) {
                cout << "Stack is empty\n";
                return;
            }
            cout << "Stack elements: ";
            for (int i = 0; i <= topIndex; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

class QueueImpUsingArray {
    private:
        int arr[maxSize];
        int front;  // Points to the front element
        int end;   // Points to the next available position
        int currSize;  // Current number of elements
    
    public:
        QueueImpUsingArray() {
            front = -1;
            end = -1;
            currSize = 0;
        }
    
        // Add an element to the queue (enqueue) or push
        void push(int value) {
            if (isFull()) {
                cout << "Queue Overflow\n";
                return;
            }
            if (currSize == 0) {
                front = 0;
                end = 0;
            }
            else {
                end = (end + 1) % maxSize;
            }

            arr[end] = value;
            currSize++;
        }
    
        // Remove and return the front element (dequeue) or pop
        int pop() {
            if (isEmpty()) {
                cout << "Queue Underflow\n";
                return -1;  // Error value
            }
            int value = arr[front];
            if (currSize == 1) {
                front = -1;
                end = -1;
            }
            front = (front + 1) % maxSize;  // Circular increment
            currSize--;
            return value;
        }
    
        // Get the front element without removing it
        int peek() {
            if (isEmpty()) {
                cout << "Queue is empty\n";
                return -1;  // Error value
            }
            return arr[front];
        }
    
        // Check if the queue is empty
        bool isEmpty() {
            return currSize == 0;
        }
    
        // Check if the queue is full
        bool isFull() {
            return currSize == maxSize;
        }
    
        // Get current size of the queue
        int size() {
            return currSize;
        }
    
        // Display all elements in the queue
        void display() {
            if (isEmpty()) {
                cout << "Queue is empty\n";
                return;
            }
            cout << "Queue elements: ";
            int i = front;
            for (int c = 0; c < currSize; c++) {
                cout << arr[i] << " ";
                i = (i + 1) % maxSize;
            }
            cout << endl;
        }
};



struct Node {
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class StackImpUsingLL {
    private:
        Node* top;
        int size;
    public:
        StackImpUsingLL() {
            top = nullptr;
            size = 0;
        }
    
        void push(int value) {
            Node* newNode = new Node(value);
            newNode->next = top;
            top = newNode;
            size++;
        }
    
        void pop() {
            if (isEmpty()) {
                cout << "Stack Underflow\n";
                return;
            }
            Node* temp = top;
            top = top->next;
            delete temp;
            size--;
        }
    
        int peek() {
            if (isEmpty()) return -1;
            return top->data;
        }
    
        bool isEmpty() {
            return top == nullptr;
        }

        void display() {
            if (isEmpty()) {
                cout << "Stack is empty \n";
                return;
            }

            Node* temp = top;
            cout << "Stack Elements are (top to bottom): ";
            while (temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }

            cout << endl;
        }

        int getSize() {
            if (top == NULL) return 0;
            return size;
        }
};


class QueueUsingLL {
    private:
        Node* front;
        Node* rear;
        int size;
    
    public:
        // Constructor
        QueueUsingLL() {
            front = rear = nullptr;
            size = 0;
        }
    
        // Enqueue (Add element to rear)
        void enqueue(int value) {
            Node* newNode = new Node(value);
    
            if (rear == nullptr) {
                front = rear = newNode;
            } else {
                rear->next = newNode;
                rear = newNode;
            }
    
            size++;
        }
    
        // Dequeue (Remove element from front)
        void dequeue() {
            if (isEmpty()) {
                cout << "Queue Underflow\n";
                return;
            }
    
            Node* temp = front;
            front = front->next;
    
            // If queue becomes empty
            if (front == nullptr) {
                rear = nullptr;
            }
    
            delete temp;
            size--;
        }
    
        // Get front element
        int getFront() {
            if (isEmpty()) {
                cout << "Queue is empty\n";
                return -1;
            }
            return front->data;
        }
    
        // Check if queue is empty
        bool isEmpty() {
            return front == nullptr;
        }
    
        // Get size of queue
        int getSize() {
            return size;
        }
    
        // Display the queue
        void display() {
            if (isEmpty()) {
                cout << "Queue is empty\n";
                return;
            }
    
            Node* temp = front;
            cout << "Queue (front to rear): ";
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << "\n";
        }
    };
    
    

int main() {
    stack<int> st;
    st.push(5);
    st.push(44);
    st.push(66);
    cout << "The last element of stack is: " << st.top() << endl;
    cout << "The size of stack is: " << st.size() << endl;
    st.pop();
    cout << "The size of stack is after popping out the element: " << st.size() << endl;

    newline;

    // // Stack Implementation using Array..................................
    StackImpUsingArr s;
    s.push(30);
    s.push(89);
    s.push(56);
    s.display();

    cout << "Top element: " << s.top() << endl;  
    s.pop();
    cout << "Popped element: " << s.pop() << endl; 
    s.display();  // Output: 10 20
    cout << "Stack size: " << s.size() << endl;  


    queue<int> q;
    q.push(5);
    q.push(44);
    cout << "The first el of queue is: " << q.front() << endl;
    cout << "The size of queue is: " << q.size() << endl;
    q.pop();
    cout << "The size of queue is after popping out the el: " << q.size() << endl;

    cout << "Queue Implementation using Array......................................................" << endl;
    QueueImpUsingArray Q;
    Q.push(10);
    Q.push(20);
    Q.push(30);

    Q.display();
    cout << "Front element: " << Q.peek() << endl;
    cout << "Dequeue element: " << Q.pop() << endl;

    Q.display();
    cout << "Queue size: " << Q.size() << endl;


    cout << "Stack implementation using Linked List...................................................... " << endl;  // //Advantages of LL:-
    // //Dynamic size (no overflow unless memory full)
    // //No need to shift elements
    

    StackImpUsingLL s2;
    s2.push(30);
    s2.push(89);
    s2.push(56);
    s2.display();

    cout << "Top element: " << s2.peek() << endl;
    s2.pop();
    s2.display(); 
    cout << "Stack size: " << s2.getSize() << endl;


    cout << "Queue implementation using Linked List............................................................" << endl;
    QueueUsingLL q2;
    q2.enqueue(7);
    q2.enqueue(2);
    q2.enqueue(3);
    q2.enqueue(5);
    q2.display();

    q2.dequeue();
    cout << "First element of Queue is: " << q2.getFront() << endl;
    q2.dequeue();
    q2.display();
    q2.dequeue();
    cout << "First element of Queue is: " << q2.getFront() << endl;
    q2.dequeue();
    q2.display();



    return 0;
}







// #include <iostream>
// #include <queue>
// using namespace std;

// class StackUsingOneQueue {
// private:
//     queue<int> q;

// public:
//     // Push operation - O(n)
//     void push(int x) {
//         int size = q.size();
//         q.push(x);

//         // Rotate the rest of the queue behind the new element
//         for (int i = 0; i < size; i++) {
//             q.push(q.front());
//             q.pop();
//         }
//     }

//     // Pop operation - O(1)
//     void pop() {
//         if (q.empty()) {
//             cout << "Stack Underflow\n";
//             return;
//         }
//         q.pop();
//     }

//     // Top operation - O(1)
//     int top() {
//         if (q.empty()) {
//             cout << "Stack is empty\n";
//             return -1;
//         }
//         return q.front();
//     }

//     // Check if stack is empty
//     bool isEmpty() {
//         return q.empty();
//     }

//     // Display elements of the stack
//     void display() {
//         if (q.empty()) {
//             cout << "Stack is empty\n";
//             return;
//         }

//         queue<int> temp = q;
//         cout << "Stack (top to bottom): ";
//         while (!temp.empty()) {
//             cout << temp.front() << " ";
//             temp.pop();
//         }
//         cout << "\n";
//     }
// };


// int main() {
//     int a = 9, b = 8;
    
// }

