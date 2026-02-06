#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define newline1 cout << "\n";
#define newline2 cout << "\n\n";
#define newline3 cout << "\n\n\n";

class CircularLinkedList {
private:
    class Node {
    public:
        int data;
        Node* next;

        Node(int val) {
            data = val;
            next = NULL;
        }
    };

    Node* head;  

public: 
    CircularLinkedList() {
        head = NULL;
    }

    // InsertEnd
    void insertEnd(int val) {
        Node* newNode = new Node(val);

        Node* temp = head;
        if (!temp) {
            head = newNode;
            head->next = head;  // Question: what if I use newNode->next = head in place of head->next = head? ----> Correct
            return;
        }

        while (temp->next != head) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = head; 
    }

    // Display
    void display() {
        if (!head) {
            cout << "Empty List" << endl;
            return;
        }

        Node* temp = head;
        cout << "Circular LinkedList:- ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);

        cout << endl;
    }

    // Insert in the beginning 
    void insertBeginning(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            newNode->next = head;
            return;
        }

        Node* end = head;
        while (end->next != head) {
            end = end->next;
        }
        newNode->next = head;
        head = newNode;
        end->next = head;
    }

    // Insert at Position
    void insertAtPos(int pos, int val) {
        int nodes = countNodes();

        if (pos < 1 || pos > nodes+1) {
            cout << "Position out of range" << endl;
            return;
        }

        if (pos == 1) {
            insertBeginning(val);
            return;
        }

        
        Node* temp = head;
        int n = 1;
        while (n != pos-1) {
            temp = temp->next;
            n++;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    
    // Insert After a value
    void insertAfter(int key, int val) {
        
    }


    int countNodes() {
        cout << "No of Nodes in CLL: " << endl;
        if (!head) {
            return 0;
        }
        
        int nodes = 0;
        Node* temp = head;
        do {
            nodes++;
            temp = temp->next;
        } while (temp != head);

        return nodes;
    }
};


int main() {
    newline2;

    CircularLinkedList cll;
    cll.insertBeginning(4);
    cll.insertBeginning(3);
    cll.insertBeginning(6);
    cll.insertBeginning(9);

    cll.display();

    

    newline2;
    return 0;
}