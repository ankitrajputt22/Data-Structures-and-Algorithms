/*
===============================================================================
EXPERIMENT: Implement Stack Using Linked List

Operations:
4. Stack Implementation using Linked List
5. PUSH Operation
6. POP Operation
7. PEEK / TOP Operation
8. isEmpty()
9. isFull()

===============================================================================
*/


#include <stdio.h>
#include <stdlib.h>

/*===============================================================================
🔹 STACK USING LINKED LIST — ALGORITHMS
---------------------------------------

PUSH(item):
1. Create newNode
2. newNode->data = item
3. newNode->next = top
4. top = newNode

POP():
1. If top == NULL → Underflow
2. Save top->data
3. Move top to next
4. Free old node
5. Return popped value

PEEK():
1. If top == NULL → Empty
2. Return top->data

isEmpty():
1. If top == NULL → return true
2. Else false

isFull():
(Linked list stack never becomes full unless memory ends)
1. Always return false

===============================================================================*/


/*-------------------------
    NODE STRUCTURE
--------------------------*/
struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;   // Stack top pointer


/*-------------------------
        isEmpty()
--------------------------*/
int isEmpty() {
    return (top == NULL);
}


/*-------------------------
        isFull()
(Linked List stack is never full unless memory runs out)
--------------------------*/
int isFull() {
    return 0;   // Always false
}


/*-------------------------
        PUSH
--------------------------*/
void push(int val) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Stack Overflow (Memory Full)!\n");
        return;
    }

    newNode->data = val;
    newNode->next = top;
    top = newNode;

    printf("Pushed: %d\n", val);
}


/*-------------------------
        POP
--------------------------*/
int pop() {
    if (isEmpty()) {
        printf("Stack Underflow!\n");
        return -1;
    }

    int value = top->data;
    struct Node* temp = top;

    top = top->next;
    free(temp);

    return value;
}


/*-------------------------
        PEEK / TOP
--------------------------*/
int peek() {
    if (isEmpty()) {
        printf("Stack is Empty!\n");
        return -1;
    }
    return top->data;
}


/*-------------------------
    DISPLAY STACK
--------------------------*/
void display() {
    if (isEmpty()) {
        printf("Stack is Empty!\n");
        return;
    }

    struct Node* temp = top;

    printf("Stack (top → bottom): ");
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


/*===============================================================================
                           MAIN — AUTOMATIC DEMONSTRATION
===============================================================================*/
int main() {

    printf("\n==============================\n");
    printf("   STACK USING LINKED LIST\n");
    printf("==============================\n\n");

    printf("Is Stack Empty? %s\n\n", isEmpty() ? "Yes" : "No");

    push(10);
    push(20);
    push(30);
    display();

    printf("Peek Element: %d\n", peek());

    printf("Popped: %d\n", pop());
    display();

    printf("Is Stack Empty? %s\n", isEmpty() ? "Yes" : "No");
    printf("Is Stack Full? %s\n", isFull() ? "Yes" : "No");

    return 0;
}
