#include <stdio.h>
#include <stdlib.h>

#define newline1 printf("\n");
#define newline2 printf("\n\n");
#define newline3 printf("\n\n\n");

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

/*---------------------------------------
        INSERT AT END
----------------------------------------*/
void insertEnd(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        head->next = head;   // same logic as your C++ code
        return;
    }

    struct Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
}

/*---------------------------------------
                DISPLAY
----------------------------------------*/
void display() {
    if (head == NULL) {
        printf("Empty List\n");
        return;
    }

    struct Node* temp = head;
    printf("Circular LinkedList:- ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("\n");
}

/*---------------------------------------
        INSERT AT BEGINNING
----------------------------------------*/
void insertBeginning(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }

    struct Node* end = head;
    while (end->next != head) {
        end = end->next;
    }

    newNode->next = head;
    head = newNode;
    end->next = head;
}

/*---------------------------------------
        COUNT NODES
----------------------------------------*/
int countNodes() {
    if (head == NULL) return 0;

    int nodes = 0;
    struct Node* temp = head;

    do {
        nodes++;
        temp = temp->next;
    } while (temp != head);

    return nodes;
}

/*---------------------------------------
        INSERT AT POSITION
----------------------------------------*/
void insertAtPos(int pos, int val) {
    int nodes = countNodes();

    if (pos < 1 || pos > nodes + 1) {
        printf("Position out of range\n");
        return;
    }

    if (pos == 1) {
        insertBeginning(val);
        return;
    }

    struct Node* temp = head;
    int n = 1;

    while (n != pos - 1) {
        temp = temp->next;
        n++;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;

    newNode->next = temp->next;
    temp->next = newNode;
}

/*---------------------------------------
        INSERT AFTER VALUE
        (EMPTY - same as C++ version)
----------------------------------------*/
void insertAfter(int key, int val) {
    // You left this empty in C++, so keeping it empty here as asked.
}

/*---------------------------------------
                MAIN
----------------------------------------*/
int main() {
    newline2;

    insertBeginning(4);
    insertBeginning(3);
    insertBeginning(6);
    insertBeginning(9);

    display();

    newline2;
    return 0;
}
