#include <iostream>
using namespace std;

// =====================================================
//                SINGLY LINKED LIST CLASS
// =====================================================
class SinglyLinkedList {
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

    Node* head;  // head pointer

public:

    // Constructor
    SinglyLinkedList() {
        head = NULL;
    }

    // =====================================================
    //              LEVEL 1 : BASIC OPERATIONS
    // =====================================================

    // 1. Insert at End (Create List)
    void insertEnd(int val) {
        Node* n = new Node(val);

        if (!head) {
            head = n;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = n;
    }

    // 2. Display the list
    void display() {
        cout << "List: ";
        Node* temp = head;

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }

    // 3. Insert at Beginning
    void insertBegin(int val) {
        Node* n = new Node(val);
        n->next = head;
        head = n;
    }

    // 4. Insert at End (Already same as create)
    // insertEnd(val) is used.

    // =====================================================
    //                LEVEL 2 : INSERTIONS
    // =====================================================

    // 5. Insert at a given position (1-based index)
    void insertAtPos(int pos, int val) {
        if (pos == 1) {
            insertBegin(val);
            return;
        }

        Node* temp = head;

        for (int i = 1; temp != NULL && i < pos - 1; i++)
            temp = temp->next;

        if (!temp) {
            cout << "Position out of range!\n";
            return;
        }

        Node* n = new Node(val);
        n->next = temp->next;
        temp->next = n;
    }

    // 6. Insert After a given value
    void insertAfter(int key, int val) {
        Node* temp = head;

        while (temp && temp->data != key)
            temp = temp->next;

        if (!temp) {
            cout << "Key not found!\n";
            return;
        }

        Node* n = new Node(val);
        n->next = temp->next;
        temp->next = n;
    }

    // 7. Insert Before a given value
    void insertBefore(int key, int val) {

        if (!head) return;

        // If inserting before first node
        if (head->data == key) {
            insertBegin(val);
            return;
        }

        Node* temp = head;

        while (temp->next && temp->next->data != key)
            temp = temp->next;

        if (!temp->next) {
            cout << "Key not found!\n";
            return;
        }

        Node* n = new Node(val);
        n->next = temp->next;
        temp->next = n;
    }

    // =====================================================
    //                LEVEL 3 : DELETIONS
    // =====================================================

    // 8. Delete from Beginning
    void deleteBegin() {
        if (!head) return;

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // 9. Delete from End
    void deleteEnd() {
        if (!head) return;

        // If only 1 node
        if (!head->next) {
            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;
        while (temp->next->next != NULL)
            temp = temp->next;

        delete temp->next;
        temp->next = NULL;
    }

    // 10. Delete at a given position
    void deleteAtPos(int pos) {
        if (!head) return;

        if (pos == 1) {
            deleteBegin();
            return;
        }

        Node* temp = head;

        for (int i = 1; temp && i < pos - 1; i++)
            temp = temp->next;

        if (!temp || !temp->next) {
            cout << "Position out of range!\n";
            return;
        }

        Node* del = temp->next;
        temp->next = del->next;
        delete del;
    }

    // 11. Delete by value (key)
    void deleteByValue(int key) {
        if (!head) return;

        if (head->data == key) {
            deleteBegin();
            return;
        }

        Node* temp = head;

        while (temp->next && temp->next->data != key)
            temp = temp->next;

        if (!temp->next) {
            cout << "Key not found!\n";
            return;
        }

        Node* del = temp->next;
        temp->next = del->next;
        delete del;
    }
};

// =====================================================
//                      MAIN MENU
// =====================================================
int main() {
    SinglyLinkedList sll;
    int ch, val, pos, key;

    while (true) {
        cout << "\n=========== SINGLY LINKED LIST MENU ===========\n";
        cout << "1. Insert at End (Create)\n";
        cout << "2. Insert at Beginning\n";
        cout << "3. Insert at Position\n";
        cout << "4. Insert After Key\n";
        cout << "5. Insert Before Key\n";
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
            sll.insertEnd(val);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> val;
            sll.insertBegin(val);
            break;

        case 3:
            cout << "Enter position: ";
            cin >> pos;
            cout << "Enter value: ";
            cin >> val;
            sll.insertAtPos(pos, val);
            break;

        case 4:
            cout << "Insert after value: ";
            cin >> key;
            cout << "Enter new value: ";
            cin >> val;
            sll.insertAfter(key, val);
            break;

        case 5:
            cout << "Insert before value: ";
            cin >> key;
            cout << "Enter new value: ";
            cin >> val;
            sll.insertBefore(key, val);
            break;

        case 6:
            sll.deleteBegin();
            break;

        case 7:
            sll.deleteEnd();
            break;

        case 8:
            cout << "Enter position: ";
            cin >> pos;
            sll.deleteAtPos(pos);
            break;

        case 9:
            cout << "Enter value to delete: ";
            cin >> key;
            sll.deleteByValue(key);
            break;

        case 10:
            sll.display();
            break;

        case 11:
            return 0;

        default:
            cout << "Invalid choice!\n";
        }
    }
}
