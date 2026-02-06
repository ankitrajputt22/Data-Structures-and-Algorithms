/*

queue<int> q;


Operation	 Syntax	         Description	                              Time Complexity
push	   q.push(value)	 Adds element to the end	                    O(1)
pop	       q.pop()	         Removes front element	                        O(1)
front	   q.front()	     Returns front element	                        O(1)
back	   q.back()	         Returns back element	                        O(1)
empty	   q.empty()	     Checks if empty	                            O(1)
size	   q.size()	         Returns number of elements	                    O(1)
emplace	   q.emplace(args)	 Constructs and inserts element	                O(1)
swap	   q1.swap(q2)	     Swaps contents with another queue	            O(1)

// 1. Push - Add element to the back
q.push(10);
q.push(20);
q.push(30);
// Queue: [10, 20, 30] (front → back)

// 2. Pop - Remove element from the front  
q.pop();
// Queue: [20, 30]

// 3. Front - Access front element
int front = q.front(); // 20

// 4. Back - Access back element
int back = q.back(); // 30

// 5. Empty - Check if queue is empty
bool isEmpty = q.empty(); // false

// 6. Size - Get number of elements
int size = q.size(); // 2

7. queue<pair<int, string>> q;
q.emplace(1, "Alice");  // More efficient than push(make_pair(1, "Alice"))
q.emplace(2, "Bob");


8. queue<int> q1, q2;
q1.push(1); q1.push(2);
q2.push(3);

q1.swap(q2);
// Now q1: [3], q2: [1, 2]

*/


#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;
    
    // Push operations
    q.push(10);
    q.push(20);
    q.push(30);
    
    cout << "Front: " << q.front() << endl; // 10
    cout << "Back: " << q.back() << endl;   // 30
    cout << "Size: " << q.size() << endl;   // 3
    
    // Pop operation
    q.pop();
    cout << "After pop - Front: " << q.front() << endl; // 20
    
    // Check empty
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    // Output: 20 30
    
    return 0;
}


