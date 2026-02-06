#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";



struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }

    Node(int val, Node* nextPointer) {
        data = val;
        next = nextPointer;
    }
};


class singlyLinkedList {
private:
    Node* head;

public:
    singlyLinkedList() {
        head = nullptr;
    }

    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);

        newNode->next = head;
        head = newNode;
    }

    // Iterative traversal
    void traverseList() {
        Node* temp = head;

        cout << "Singly LL (Iterative): ";

        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) {
                cout << " -> ";
            }
            
            temp = temp->next;
        }

        cout << " -> NULL \n";
    }


private:
    // helper function (actual recursion)
    void traverseListRecursiveHelper(Node* node) {
        if (node == nullptr) return;

        cout << node->data;
        if (node->next != nullptr) {
            cout << " -> ";
        }
            
        traverseListRecursiveHelper(node->next);
    }

public:
    // Recursive traversal 
    void traverseListRecursive() {
        cout << "Singly LL (Recursive): ";

        traverseListRecursiveHelper(head);

        cout << " -> NULL\n";
    }


    


};




int main() {
    newline1;

    singlyLinkedList l1;
    l1.insertAtBeginning(1);
    l1.insertAtBeginning(2);
    l1.insertAtBeginning(3);

    l1.traverseList();
    l1.traverseListRecursive();
    newline2;






    return 0;
}