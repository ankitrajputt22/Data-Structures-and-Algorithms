#include <iostream>
using namespace std;

// ====================================================
//            CIRCULAR LINKED LIST CLASS
// ====================================================

class CircularLinkedList {
private:

    // ---------------- NODE DEFINITION ----------------
    class Node {
    public:
        int data;
        Node* next;

        Node(int val) {
            data = val;
            next = NULL;
        }
    };

    Node* head;  // pointer to first node

    // Utility: Count number of nodes
    int countNodes() {
        if (!head) return 0;

        int count = 1;
        Node* temp = head;

        while (temp->next != head) {
            temp = temp->next;
            count++;
        }

        return count;
    }

public:
    // Constructor
    CircularLinkedList() {
        head = NULL;
    }

    // ====================================================
    //           LEVEL 1 : BASIC OPERATIONS
    // ====================================================

    // 1. Insert at End (Create / Normal Insert End)
    void insertEnd(int val) {
        Node* n = new Node(val);

        if (!head) {
            head = n;
            n->next = head;
            return;
        }

        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;

        temp->next = n;
        n->next = head;
    }

    // 2. Display the Circular List
    void display() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;
        cout << "Circular List: ";

        // Safety counter to avoid infinite loop if corrupted (should never happen now)
        int safety = 0;

        do {
            cout << temp->data << " ";
            temp = temp->next;

            safety++;
            if (safety > 10000) {  
                cout << "\nERROR: List corrupted!\n";
                return;
            }

        } while (temp != head);

        cout << "\n";
    }

    // 3. Insert at Beginning
    void insertBegin(int val) {
        Node* n = new Node(val);

        if (!head) {
            head = n;
            n->next = head;
            return;
        }

        Node* temp = head;

        // Go to last node
        while (temp->next != head)
            temp = temp->next;

        n->next = head;
        temp->next = n;
        head = n;
    }

    // ====================================================
    //           LEVEL 2 : INSERT OPERATIONS
    // ====================================================

    // 4. Insert at a given position (1-based index)
    void insertAtPos(int pos, int val) {
        int total = countNodes();

        if (pos < 1 || pos > total + 1) {
            cout << "Position out of range!\n";
            return;
        }

        if (pos == 1) {
            insertBegin(val);
            return;
        }

        Node* temp = head;

        for (int i = 1; i < pos - 1; i++)
            temp = temp->next;

        Node* n = new Node(val);
        n->next = temp->next;
        temp->next = n;
    }

    // 5. Insert AFTER a value
    void insertAfter(int key, int val) {
        if (!head) return;

        Node* temp = head;

        do {
            if (temp->data == key) {
                Node* n = new Node(val);
                n->next = temp->next;
                temp->next = n;
                return;
            }
            temp = temp->next;
        } while (temp != head);

        cout << "Key not found!\n";
    }

    // 6. Insert BEFORE a value
    void insertBefore(int key, int val) {
        if (!head) return;

        // If key is at head
        if (head->data == key) {
            insertBegin(val);
            return;
        }

        Node* temp = head;

        // Find node before key
        while (temp->next != head && temp->next->data != key)
            temp = temp->next;

        if (temp->next == head) {
            cout << "Key not found!\n";
            return;
        }

        Node* n = new Node(val);
        n->next = temp->next;
        temp->next = n;
    }

    // ====================================================
    //            LEVEL 3 : DELETE OPERATIONS
    // ====================================================

    // 7. Delete from Beginning
    void deleteBegin() {
        if (!head) return;

        // Only 1 node case
        if (head->next == head) {
            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;
        Node* last = head;

        while (last->next != head)
            last = last->next;

        head = head->next;
        last->next = head;
        delete temp;
    }

    // 8. Delete from End
    void deleteEnd() {
        if (!head) return;

        // Only 1 node
        if (head->next == head) {
            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;

        while (temp->next->next != head)
            temp = temp->next;

        Node* last = temp->next;
        temp->next = head;
        delete last;
    }

    // 9. Delete at a given position
    void deleteAtPos(int pos) {
        int total = countNodes();

        if (pos < 1 || pos > total) {
            cout << "Position out of range!\n";
            return;
        }

        if (pos == 1) {
            deleteBegin();
            return;
        }

        Node* temp = head;

        for (int i = 1; i < pos - 1; i++)
            temp = temp->next;

        Node* del = temp->next;
        temp->next = del->next;
        delete del;
    }

    // 10. Delete by value
    void deleteByValue(int key) {
        if (!head) return;

        // If key is at head
        if (head->data == key) {
            deleteBegin();
            return;
        }

        Node* temp = head;

        while (temp->next != head && temp->next->data != key)
            temp = temp->next;

        if (temp->next == head) {
            cout << "Key not found!\n";
            return;
        }

        Node* del = temp->next;
        temp->next = del->next;
        delete del;
    }
};

// ====================================================
//                    MAIN MENU
// ====================================================

int main() {
    CircularLinkedList cll;
    int ch, val, pos, key;
    int test = 15;

    while (true) {
        cout << "\n=========== CIRCULAR LINKED LIST MENU ===========\n";
        cout << "1. Insert at End (Create)\n";
        cout << "2. Insert at Beginning\n";
        cout << "3. Insert at Position\n";
        cout << "4. Insert After a Value\n";
        cout << "5. Insert Before a Value\n";
        cout << "6. Delete from Beginning\n";
        cout << "7. Delete from End\n";
        cout << "8. Delete at Position\n";
        cout << "9. Delete by Value\n";
        cout << "10. Display List\n";
        cout << "11. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            cll.insertEnd(val);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> val;
            cll.insertBegin(val);
            break;

        case 3:
            cout << "Enter position: ";
            cin >> pos;
            cout << "Enter value: ";
            cin >> val;
            cll.insertAtPos(pos, val);
            break;

        case 4:
            cout << "Insert after value: ";
            cin >> key;
            cout << "Enter new value: ";
            cin >> val;
            cll.insertAfter(key, val);
            break;

        case 5:
            cout << "Insert before value: ";
            cin >> key;
            cout << "Enter new value: ";
            cin >> val;
            cll.insertBefore(key, val);
            break;

        case 6:
            cll.deleteBegin();
            break;

        case 7:
            cll.deleteEnd();
            break;

        case 8:
            cout << "Enter position: ";
            cin >> pos;
            cll.deleteAtPos(pos);
            break;

        case 9:
            cout << "Enter value to delete: ";
            cin >> key;
            cll.deleteByValue(key);
            break;

        case 10:
            cll.display();
            break;

        case 11:
            return 0;

        default:
            cout << "Invalid choice!\n";
        }
    }
}
