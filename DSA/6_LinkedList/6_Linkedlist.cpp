//L1. Introduction to LinkedList | Traversal | Length | Search an Element @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

#include <iostream>
using namespace std;

struct Node {                        //if we use class, We can use concepts of OOPS
    public:
        int data;
        Node* next;

        Node (int data1, Node* next1) {   //This is a constructor. Constructors are methods that are automatically executed every time you create an object
            data = data1;
            next = next1;
        }

        Node (int data1) {
            data = data1;
            next = nullptr;
        }
};

Node* convertArr2LL(vector<int> &arr) {
    Node* head = new Node(arr[0]);
    Node* mover = head;                //Never ever temper the head

    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover -> next = temp;
        mover = temp;
    }

    return head;
}

auto traversal_in_linkedlist(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;

}

int lengthofLL(Node* head) {
    int cnt = 0;
    Node* temp = head;
    while(temp) {
        // cout << temp -> data << " " ;
        temp = temp -> next;
        cnt++;
    }

    return cnt;
}

int search_element(Node* head, int val) {
    Node* temp = head;    
    while(temp) {
        if ((temp -> data) == val) {
            return 1;
        }

        temp = temp -> next;
    }

    return 0;
}

int main() {
    // //Pointer to memory location...............
    // int a = 2;
    // int* b = &a;
    // cout << b << endl;
    // cout << *b << endl;
    

    // vector<int> arr1 = {1333, 1, 2, 3};
    // Node* y = new Node(arr1[0], nullptr);                         //pointer to the memory location
    // cout << "Pointer to memory location is: " << y << endl;      //gives you the pointer to memory location
    // // cout << y.data  <<endl;                            //will give you an error as y is pointer to memory location not an object or variable
    // cout << "The value at pointer y is: " << y -> data << endl;


    // Node z = Node(arr1[1], nullptr);     //we are just creating an object. This is just a variable not the memory location. In order to get pointer to z we have to do the following thing
    // Node* p = &z;
    // cout << "This will give you pointer to memory location: " << p << endl;
    // // cout << z << endl;               //gives you error because it is an object. We can take data from it or we can print next;
    // cout << "Value at object z: " << z.data << endl;
    // cout << "Pointer to next of z: " << z.next << endl;     //z's next is pointing to nullptr
    // // cout << "Value of next is: " << z.next -> data << endl;  //The segmentation fault occurs in your last line because you're trying to dereference a nullptr

    // //we can also define a node like this because we have multiple constructor
    // Node r = Node(arr1[1]);
    // cout << "The data field of object of r is: " << r.data << endl;
    // Node* s = new Node(arr1[1]);
    // cout << "The data at pointer s: " << s -> data << endl;
    // cout << "The pointer pointing at s is: " << s << endl;


    
    // //Conversion of Array to Linked List..................................................................
    // vector<int> arr2 = {1333, 3, 4, 4};
    // Node* head = convertArr2LL(arr2);        
    // cout << "Head of the linked list is: " << head -> data << endl;
    
    // //Traversal in linked list............................................................................
    // //Linked list is printed as follows: .................................................................
    // cout << "Linked list is printed as follows: " << endl;
    // traversal_in_linkedlist(head);

    // cout <<"Length of linked list : " << lengthofLL(head) << endl;

    // cout <<"Check if Present: " << search_element(head, 4) << endl;

}


//All details about every line ................................................................................
class Node{
    Public: // access modifier
    int data; // the data value
    Node* next; // the pointer to the next value
    Public:
    // constructor
    Node (int data1, Node* next1){
        data=data1;  // Initialize data with the provided value
        next=next1;  // Initialize next with the provided
    }
    Node (int data1){
        data=data1;  // Initialize data with the provided value
        next=nullptr;  // Initialize next as null since it's the end of the list

    }
};
int main(){
    vector<int> arr={2,5,8,7};
    Node* y= new Node(arr[0]);
    cout<<y<<'\n'; // returns the memory value
    cout<<y->data<<'\n'; // returns the data stored at that memory point
}




//L2. Deletion and Insertion in LL | 8 Problems @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


//DELETION in a Linked List............................................................................@@@@@@@@@@@@@@@@@@@@@@@@
// #include <iostream>
// using namespace std;

// struct Node {                        // if we use class, We can use concepts of OOPS
//     int data;
//     Node* next;

//     Node (int data1, Node* next1) {       // This is a constructor. Constructors are methods that are automatically executed every time you create an object
//         data = data1;
//         next = next1;
//     }

//     // Node (int data1) {
//     //     data = data1;
//     //     next = nullptr;
//     // }
//     Node (int x) : data(x), next(NULL) {}   //we can also write commented code like this
// };

// Node* convertArr2LL(vector<int> &arr) {
//     Node* head = new Node(arr[0]);
//     Node* mover = head;                //Never ever temper the head

//     for (int i = 1; i < arr.size(); i++) {
//         Node* temp = new Node(arr[i]);
//         mover -> next = temp;
//         mover = temp;
//     }

//     return head;
// }

// void PrintLL(Node* head) {
//     Node* temp = head;
//     while (temp) {
//         cout << temp -> data << " ";
//         temp = temp -> next;
//     }
//     cout << endl;
// }

// Node* removesHead(Node* head) {
//     if (head == NULL) {
//         return head;
//     }

//     Node* temp = head;
//     head = head -> next;
//     // delete temp;
//     free(temp);      

//     return head;
// }

// Node* removesTail(Node* head) {
//     if (head == NULL || head -> next == NULL) {
//         return nullptr;
//     }
//     Node* temp = head;

//     while (temp -> next -> next != NULL) {
//         temp = temp -> next;
//     }

//     delete temp -> next;
//     temp -> next = nullptr;

//     return head;
// }

// Node* removeKthEl(Node* head, int k) {
//     if (head == NULL) return head;
//     if (k == 1) {
//         Node* temp = head;
//         head = head -> next;
//         delete temp;
//         return head;
//     }

//     Node* prev = NULL;
//     Node* temp = head;
//     int cnt = 0;
//     while(temp != NULL) {
//         cnt++;
//         if (cnt == k) {
//             prev -> next = prev -> next -> next;
//             delete temp;
//             break;
//         }

//         prev = temp;
//         temp = temp -> next;
//     }

//     return head;
// }

// Node* removeEl(Node* head, int el) {
//     if (head == NULL) return head;
//     if (head -> data == el) {
//         Node* temp = head;
//         head = head -> next;
//         delete temp;
//         return head;
//     }

//     Node* prev = NULL;
//     Node* temp = head;
//     while(temp != NULL) {
//         if (temp -> data == el) {
//             prev -> next = prev -> next -> next;
//             delete temp;
//             break;
//         }
//         prev = temp;
//         temp = temp -> next;
//     }

//     return head;
// }

// int main() {
//     vector<int> arr2 = {5, 8, 9, 4, 10};
//     Node* head = convertArr2LL(arr2); 
//     cout << "Original Linked list is printed as: "; 
//     PrintLL(head);       
//     cout << "Original head of LL: " << head -> data << endl;

//     head = removesHead(head);
//     cout << "New Linked List after deletion of head : ";
//     PrintLL(head);
//     cout << "New head is: " << head -> data << endl;

//     head = removesTail(head);
//     cout << "New LL after deletion of tail: ";
//     PrintLL(head);

//     head = removeKthEl(head, 3);
//     cout << "linked list after removing the kth element: ";
//     PrintLL(head);

//     head = removeEl(head, 8);
//     cout << "linked list after removing a given element/node: ";
//     PrintLL(head);

// }



//Insertion in LL ...........................@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\

// #include <iostream>
// using namespace std;

// struct Node {                        //if we use class, We can use concepts of OOPS
//     int data;
//     Node* next;

//     Node (int data1, Node* next1) {       //This is a constructor. Constructors are methods that are automatically executed every time you create an object
//         data = data1;
//         next = next1;
//     }

//     // Node (int data1) {
//     //     data = data1;
//     //     next = nullptr;
//     // }
//     Node (int x) : data(x), next(NULL) {}
// };

// Node* convertArr2LL(vector<int> &arr) {
//     Node* head = new Node(arr[0]);
//     Node* mover = head;                //Never ever temper the head

//     for (int i = 1; i < arr.size(); i++) {
//         Node* temp = new Node(arr[i]);
//         mover->next = temp;
//         mover = temp;
//     }

//     return head;
// }

// void PrintLL(Node* head) {
//     Node* temp = head;
//     while (temp) {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     cout << endl;
// }

// Node* insertHead(Node* head, int val) {
//     Node* temp = new Node(val, head);
//     return temp;
// }

// Node* insertTail(Node* head, int val) {
//     if (head == NULL) {
//         return new Node(val);
//     }
    
//     Node* temp = head;
//     while(temp->next != NULL) {
//         temp = temp->next;
//     }

//     Node* newNode = new Node(val);
//     temp->next = newNode;
//     return head;
// }

// Node* insertAtPosition(Node* head, int el, int k) {
//     if (head == NULL) {
//         if (k == 1) {
//             Node* temp = new Node(el);
//             return temp;
//         }
//         else {
//             return head;
//         }
//     }
//     if (k == 1) {
//         Node* temp = new Node(el, head);
//         return temp;
//     }

//     int cnt = 0;
//     Node* temp = head;
//     while (temp != NULL) {
//         cnt++;
//         if (cnt == k - 1) {
//             Node* x = new Node(el);
//             x->next = temp->next;
//             temp->next = x;
//             break;
//         }
//         temp = temp->next;
//     }
//     return head;
// }

// Node* insertBeforeVal(Node* head, int el, int val) {
//     if (head == NULL) {
//         return nullptr;
//     }
//     if (head->data == val) {
//         Node* temp = new Node(el, head);
//         return temp;
//     }
//     bool found = false;

//     Node* temp = head;
//     while (temp->next != NULL) {
//         if (temp->next->data == val) {
//             Node* x = new Node(el);
//             x->next = temp->next;
//             temp->next = x;
//             found = 1;
//             break;
//         }
//         temp = temp->next;
//     }
//     if (found == false) {
//         cout << "The given value is not in the LL" << endl;
//     }

//     return head;
// }

// int main() {
//     vector<int> arr2 = {5, 8, 9, 4, 10};
//     Node* head = convertArr2LL(arr2);  
 
//     head = insertHead(head, 100);
//     cout << "Insert Head function will give: ";
//     PrintLL(head);
//     //we can also insert head like this.....
//     head = new Node(9999, head);
//     cout << "We can also insert head like this: ";
//     PrintLL(head); 

//     head = insertTail(head, 988888);
//     cout << "After inserting tail LL will look like: ";
//     PrintLL(head);

//     head = insertAtPosition(head, 69, 5);
//     cout << "After inserting val at kth position LL will look like: ";
//     PrintLL(head);

//     head = insertBeforeVal(head, 7777, 99);
//     cout << "insertBeforeVal will give LL as follows: ";
//     PrintLL(head);
// }




//L3. Introduction to Doubly LinkedList | Insertions and Deletions @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node* back;

    public: 
        Node(int data1, Node* next1, Node* back1) {
            data = data1;
            next = next1;
            back = back1;
        }

    public:
        Node(int data1) {
            data = data1;
            next = nullptr;
            back = nullptr;
        }
};

Node* converArr2DLL(vector<int> &arr) {
    Node* head = new Node(arr[0]);
    Node* prev = head;                   //never ever temper the head
    
    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }

    return head;
}

void printDLL(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " " ;
        temp = temp->next;
    }
    cout << endl;
}

Node* DeleteHead(Node* head) {
    if (head == NULL || head->next == NULL) {
        return NULL;
    }

    Node* prev = head;
    head = head->next;

    head->back = nullptr;
    prev->next = nullptr;
    
    delete prev;

    return head;
}

Node* DeleteTail(Node* head) {
    if (head == NULL || head->next == NULL) {
        return NULL;
    }

    Node* tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;
    }

    Node* prev = tail->back;   //prev = newTail
    prev->next = NULL;
    tail->back = nullptr;
    
    delete tail;
    
    return head;
}

Node* removeKthEl(Node* head, int k) {
    if (head == NULL) return NULL;

    int cnt = 0;
    Node* kNode = head;
    while (kNode != NULL) {
        cnt++;
        if (cnt == k) {
            break;
        }
        kNode = kNode->next;
    }

    Node* back = kNode->back;
    Node* front = kNode->next;

    if (back == NULL && front == NULL) {
        return NULL;
    }
    else if (back == NULL) {
        head = DeleteHead(head);
        return head;
    }
    else if (front == NULL) {
        return DeleteTail(head);
    }
    
    back->next = front;
    front->back = back;
    kNode->next = NULL;
    kNode->back = NULL;
    
    free(kNode);
    return head;
}

Node* deleteNode(Node* head, int el) {
    if (head == NULL) return head;

    Node* temp = head;
    Node* back = temp->back;
    Node* front = temp->next;
    
    if (head->data == el) {
        if (head->next == NULL) return NULL;
        head = head->next;
        temp->next = NULL;
        delete temp;
        front->back = NULL;

        return head;
    }

    while (temp != NULL) {
        if (temp->data == el && temp->next == NULL) {
            back = temp->back;
            back->next = NULL;
            temp->back = NULL;
            
            delete temp;

            return head;
        }
        else if (temp->data == el) {
            back = temp->back;
            front = temp->next;

            back->next = front;
            front->back = back;

            temp->next = temp->back = nullptr;
            delete temp;

            return head;
        }
        temp = temp->next;
    }
    return head;
}

Node* deleteNodeDeepSeek(Node* head, int el) {
    if (head == nullptr) return head;

    // Case 1: Delete head node
    if (head->data == el) {
        Node* newHead = head->next;
        if (newHead != nullptr) {
            newHead->back = nullptr;
        }
        delete head;
        return newHead;
    }

    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == el) {
            Node* back = temp->back;
            Node* front = temp->next;

            // Update back node's next pointer
            back->next = front;

            // Update front node's back pointer if it exists
            if (front != nullptr) {
                front->back = back;
            }

            // Clean up and delete
            temp->next = temp->back = nullptr;
            delete temp;
            temp = nullptr;  // Good practice

            return head;
        }
        temp = temp->next;
    }

    // Element not found
    return head;
}

Node* insertBeforeHead(Node* head, int val) {
    Node* newHead = new Node(val, head, nullptr);
    head->back = newHead;

    return newHead;
}

Node* insertBeforeTail(Node* head, int val) {
    if (head->next == NULL) {
        return insertBeforeHead(head, val);
    }

    Node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    
    Node* prev = tail->back;
    Node* newNode = new Node(val, tail, prev);
    prev->next = newNode;
    tail->back = newNode;

    return head;
}

Node* insertBeforeKthEl(Node* head, int k, int val) {
    if (k == 1) return insertBeforeHead(head, val);

    Node* temp = head;
    int cnt = 0;
    while (temp != NULL) {
        cnt++;
        if (cnt == k) break;
        temp = temp->next;
    }

    Node* prev = temp->back;
    Node* newNode = new Node(val, temp, prev);
    prev->next = newNode;
    temp->back = newNode;

    return head;
}

void insertBeforeGivenNode(Node* node, int val) {    //node != head and we created this fn as void as we don't want to alter head
    Node* prev = node->back;
    Node* newNode = new Node(val, node, prev);
    prev->next = newNode;
    node->back = newNode;
}

//To do - After insertions in DLL

int main() {
    vector<int> arr = {2, 5, 7, 9, 55, 66, 99, 9950};

    Node* head1 = new Node(arr[0], nullptr, nullptr);     //pointer to the memory location
    cout <<"This will print the address: " << head1 << endl;
    cout <<"This will give data present at address head1: " << head1->data << endl;

    Node head2 = Node(arr[3]);     //we are just creating an object. This is just a variable not the memory location. In order to get pointer to z we have to do the following thing
    Node* p = &head2;  
    cout <<"This will give you pointer to memory location: " << p << endl;
    cout <<"This will give data present at object head2: " << head2.data << endl;


    Node* head = converArr2DLL(arr);

    cout << "converArr2DLL(arr) will give output: "; 
    printDLL(head); 

    cout << "DeleteHead(Node* head) will give output: ";
    head = DeleteHead(head);
    printDLL(head);

    cout << "DeleteTail(Node* head) will give output: ";
    head = DeleteTail(head);
    printDLL(head);

    cout << "removeKthEl(Node* head, int k) will give output: ";
    head = removeKthEl(head, 4);
    printDLL(head);

    cout << "deleteNode(Node* head, int el) will give output as: ";
    head = deleteNode(head, 5);
    printDLL(head);

    cout << "Node* insertBeforeHead(Node* head, int val) will give output as: ";
    head = insertBeforeHead(head, 10);
    printDLL(head);

    cout << "Node* insertBeforeTail(Node* head, int val) will give output as: ";
    head = insertBeforeTail(head, 69);
    printDLL(head);

    cout << "Node* insertBeforeKthEl(Node* head, int k, int val) will give output as: ";
    head = insertBeforeKthEl(head, 3, 90);
    printDLL(head);

    cout << "void insertBeforeGivenNode(Node* node, int val) will give output as: ";
    insertBeforeGivenNode(head->next->next, 69090);
    printDLL(head);
    
    return 0;
}