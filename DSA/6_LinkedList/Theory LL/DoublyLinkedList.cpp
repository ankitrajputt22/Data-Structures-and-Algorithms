#include <iostream>
using namespace std;

// -----------------------------------------------------
//                NODE STRUCTURE
// -----------------------------------------------------
class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = next = nullptr;
    }
};

// Head pointer for DLL
Node* head = nullptr;

// =====================================================
//                 LEVEL 1 : BASIC OPERATIONS
// =====================================================

// 1. Insert at End (used for creating DLL)
void insertEnd(int val) {
    Node* n = new Node(val);

    if (head == nullptr) {
        head = n;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = n;
    n->prev = temp;
}

// 2. Display forward
void displayForward() {
    Node* temp = head;
    cout << "DLL (Forward): ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

// 3. Display backward
void displayBackward() {
    if (head == nullptr) return;

    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    cout << "DLL (Backward): ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << "\n";
}

// 4. Insert at Beginning
void insertBegin(int val) {
    Node* n = new Node(val);

    if (head == nullptr) {
        head = n;
        return;
    }

    n->next = head;
    head->prev = n;
    head = n;
}

// -----------------------------------------------------
//        LEVEL 2 : IMPORTANT INSERTIONS
// -----------------------------------------------------

// 5. Insert at a given position (1-based index)
void insertAtPos(int pos, int val) {
    if (pos == 1) {
        insertBegin(val);
        return;
    }

    Node* temp = head;
    for (int i = 1; temp != nullptr && i < pos - 1; i++)
        temp = temp->next;

    if (temp == nullptr) {
        cout << "Position out of range!\n";
        return;
    }

    Node* n = new Node(val);
    n->next = temp->next;
    n->prev = temp;

    if (temp->next != nullptr)
        temp->next->prev = n;

    temp->next = n;
}

// 6. Insert after a given value
void insertAfter(int key, int val) {
    Node* temp = head;

    while (temp != nullptr && temp->data != key)
        temp = temp->next;

    if (temp == nullptr) {
        cout << "Key not found!\n";
        return;
    }

    Node* n = new Node(val);
    n->next = temp->next;
    n->prev = temp;

    if (temp->next != nullptr)
        temp->next->prev = n;

    temp->next = n;
}

// 7. Insert before a given value
void insertBefore(int key, int val) {
    if (head == nullptr) return;

    if (head->data == key) {
        insertBegin(val);
        return;
    }

    Node* temp = head;

    while (temp != nullptr && temp->data != key)
        temp = temp->next;

    if (temp == nullptr) {
        cout << "Key not found!\n";
        return;
    }

    Node* n = new Node(val);
    n->prev = temp->prev;
    n->next = temp;

    temp->prev->next = n;
    temp->prev = n;
}

// -----------------------------------------------------
//            LEVEL 3 : DELETION OPERATIONS
// -----------------------------------------------------

// 8. Delete from beginning
void deleteBegin() {
    if (head == nullptr) return;

    Node* temp = head;
    head = head->next;

    if (head != nullptr)
        head->prev = nullptr;

    delete temp;
}

// 9. Delete from end
void deleteEnd() {
    if (head == nullptr) return;

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->prev->next = nullptr;
    delete temp;
}

// 10. Delete at a given position
void deleteAtPos(int pos) {
    if (head == nullptr) return;

    if (pos == 1) {
        deleteBegin();
        return;
    }

    Node* temp = head;

    for (int i = 1; temp != nullptr && i < pos; i++)
        temp = temp->next;

    if (temp == nullptr) {
        cout << "Position out of range!\n";
        return;
    }

    if (temp->next != nullptr)
        temp->next->prev = temp->prev;

    temp->prev->next = temp->next;
    delete temp;
}

// 11. Delete a node by value
void deleteByValue(int key) {
    if (head == nullptr) return;

    if (head->data == key) {
        deleteBegin();
        return;
    }

    Node* temp = head;

    while (temp != nullptr && temp->data != key)
        temp = temp->next;

    if (temp == nullptr) {
        cout << "Key not found!\n";
        return;
    }

    if (temp->next != nullptr)
        temp->next->prev = temp->prev;

    temp->prev->next = temp->next;

    delete temp;
}

// -----------------------------------------------------
//                     MAIN MENU
// -----------------------------------------------------

int main() {
    int choice, val, pos, key;

    while (true) {
        cout << "\n================ DOUBLY LINKED LIST MENU ================\n";
        cout << "1. Insert at End (Create DLL)\n";
        cout << "2. Insert at Beginning\n";
        cout << "3. Insert at Position\n";
        cout << "4. Insert After a Value\n";
        cout << "5. Insert Before a Value\n";
        cout << "6. Delete from Beginning\n";
        cout << "7. Delete from End\n";
        cout << "8. Delete at Position\n";
        cout << "9. Delete by Value\n";
        cout << "10. Display Forward\n";
        cout << "11. Display Backward\n";
        cout << "12. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            insertEnd(val);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> val;
            insertBegin(val);
            break;

        case 3:
            cout << "Enter position: ";
            cin >> pos;
            cout << "Enter value: ";
            cin >> val;
            insertAtPos(pos, val);
            break;

        case 4:
            cout << "Insert after what value? ";
            cin >> key;
            cout << "Enter value to insert: ";
            cin >> val;
            insertAfter(key, val);
            break;

        case 5:
            cout << "Insert before what value? ";
            cin >> key;
            cout << "Enter value to insert: ";
            cin >> val;
            insertBefore(key, val);
            break;

        case 6:
            deleteBegin();
            break;

        case 7:
            deleteEnd();
            break;

        case 8:
            cout << "Enter position to delete: ";
            cin >> pos;
            deleteAtPos(pos);
            break;

        case 9:
            cout << "Enter value to delete: ";
            cin >> key;
            deleteByValue(key);
            break;

        case 10:
            displayForward();
            break;

        case 11:
            displayBackward();
            break;

        case 12:
            cout << "Exiting...\n";
            return 0;

        default:
            cout << "Invalid choice!\n";
        }
    }
}
