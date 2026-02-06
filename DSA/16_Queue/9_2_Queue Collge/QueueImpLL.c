/*
===============================================================================
EXPERIMENT: Linked List Implementation of Ordinary Queue

Operations:
1. Enqueue (Insert at REAR)
2. Dequeue (Delete from FRONT)
3. Peek / Front
4. isEmpty()
5. Display Queue
===============================================================================
*/

#include <stdio.h>
#include <stdlib.h>

/*===============================================================================
🔹 QUEUE USING LINKED LIST — ALGORITHMS
---------------------------------------

ENQUEUE(item):
1. Create newNode
2. If queue empty:
       front = rear = newNode
   Else:
       rear->next = newNode
       rear = newNode

DEQUEUE():
1. If front == NULL → Underflow
2. Save value = front->data
3. Move front = front->next
4. If front == NULL → rear = NULL
5. Free old node
6. Return value

PEEK():
1. If queue empty → no element
2. Return front->data

isEmpty():
1. If front == NULL → return true
2. Else → false
===============================================================================*/


/*-------------------------
        NODE STRUCTURE
--------------------------*/
struct Node {
    int data;
    struct Node* next;
};

struct Node *front = NULL, *rear = NULL;


/*-------------------------
          isEmpty()
--------------------------*/
int isEmpty() {
    return (front == NULL);
}


/*-------------------------
          ENQUEUE
--------------------------*/
void enqueue(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    if (front == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    printf("Enqueued: %d\n", val);
}


/*-------------------------
          DEQUEUE
--------------------------*/
int dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow!\n");
        return -1;
    }

    int val = front->data;
    struct Node* temp = front;

    front = front->next;
    if (front == NULL)
        rear = NULL;

    free(temp);
    return val;
}


/*-------------------------
          PEEK
--------------------------*/
int peek() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return -1;
    }
    return front->data;
}


/*-------------------------
          DISPLAY
--------------------------*/
void display() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return;
    }

    struct Node* temp = front;
    printf("Queue (front → rear): ");

    while (temp != NULL) {
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
    printf("   ORDINARY QUEUE (LINKED LIST)\n");
    printf("==============================\n\n");

    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    printf("Front element = %d\n", peek());

    printf("Dequeued: %d\n", dequeue());
    display();

    printf("Dequeued: %d\n", dequeue());
    display();

    printf("Queue Empty? %s\n", isEmpty() ? "Yes" : "No");

    return 0;
}
