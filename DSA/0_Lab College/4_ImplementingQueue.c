/*
===============================================================================
EXPERIMENT – 4
QUEUE IMPLEMENTATION TECHNIQUES
===============================================================================
Includes:
1. Ordinary Queue using Linked List
2. Circular Queue using Array
3. Priority Queue using Linked List
4. Double Ended Queue (Deque)
===============================================================================
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

/*===============================================================================
SECTION 1 : ORDINARY QUEUE USING LINKED LIST
===============================================================================*/

/*---------------- ALGORITHM ----------------
ENQUEUE_LL(item):
1. Create new node
2. If front == NULL → front = rear = newNode
3. Else rear->next = newNode, rear = newNode

DEQUEUE_LL():
1. If front == NULL → Underflow
2. Else remove front node, move pointer
---------------------------------------------*/

struct Node {
    int data;
    struct Node* next;
};

struct Node *frontLL = NULL, *rearLL = NULL;

void enqueueLL(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    if (rearLL == NULL)
        frontLL = rearLL = newNode;
    else {
        rearLL->next = newNode;
        rearLL = newNode;
    }
}

void dequeueLL() {
    if (frontLL == NULL) {
        printf("Queue Underflow!\n");
        return;
    }
    struct Node* temp = frontLL;
    printf("Dequeued (LL): %d\n", temp->data);
    frontLL = frontLL->next;

    if (frontLL == NULL) rearLL = NULL;
    free(temp);
}

void displayLL() {
    printf("Ordinary Queue (LL): ");
    struct Node* temp = frontLL;
    if (!temp) { printf("Empty\n"); return; }
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


/*===============================================================================
SECTION 2 : CIRCULAR QUEUE USING ARRAY
===============================================================================*/

/*---------------- ALGORITHM ----------------
ENQUEUE_C(item):
1. If (front==0 & rear==MAX-1) or (rear+1==front) → Overflow
2. Else rear = (rear+1)%MAX
3. Insert item

DEQUEUE_C():
1. If front == -1 → Underflow
2. Else front = (front+1)%MAX
---------------------------------------------*/

int cqueue[MAX];
int frontC = -1, rearC = -1;

void enqueueC(int val) {
    if ((frontC == 0 && rearC == MAX - 1) || (rearC + 1 == frontC)) {
        printf("Circular Queue Overflow!\n");
        return;
    }

    if (frontC == -1) frontC = 0;
    rearC = (rearC + 1) % MAX;
    cqueue[rearC] = val;
}

void dequeueC() {
    if (frontC == -1) {
        printf("Circular Queue Underflow!\n");
        return;
    }

    printf("Dequeued (CIRC): %d\n", cqueue[frontC]);

    if (frontC == rearC)
        frontC = rearC = -1;
    else
        frontC = (frontC + 1) % MAX;
}

void displayC() {
    if (frontC == -1) {
        printf("Circular Queue: Empty\n");
        return;
    }
    printf("Circular Queue: ");
    int i = frontC;
    while (1) {
        printf("%d ", cqueue[i]);
        if (i == rearC) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}


/*===============================================================================
SECTION 3 : PRIORITY QUEUE USING LINKED LIST
===============================================================================*/

/*---------------- ALGORITHM ----------------
ENQUEUE_PRIORITY(item, priority):
1. Create node
2. If list empty OR node.priority < front.priority → insert at front
3. Otherwise find position and insert

DEQUEUE_PRIORITY():
1. Remove from front (highest priority)
---------------------------------------------*/

struct PNode {
    int data;
    int priority;
    struct PNode* next;
};

struct PNode* pfront = NULL;

void enqueuePriority(int val, int pr) {
    struct PNode* newNode = (struct PNode*)malloc(sizeof(struct PNode));
    newNode->data = val;
    newNode->priority = pr;
    newNode->next = NULL;

    if (!pfront || pr < pfront->priority) {
        newNode->next = pfront;
        pfront = newNode;
    } else {
        struct PNode* temp = pfront;
        while (temp->next && temp->next->priority <= pr)
            temp = temp->next;

        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void dequeuePriority() {
    if (!pfront) {
        printf("Priority Queue Underflow!\n");
        return;
    }
    printf("Dequeued (Priority): %d\n", pfront->data);
    struct PNode* temp = pfront;
    pfront = pfront->next;
    free(temp);
}

void displayPriority() {
    printf("Priority Queue: ");
    struct PNode* temp = pfront;
    if (!temp) { printf("Empty\n"); return; }

    while (temp) {
        printf("[%d(p%d)] ", temp->data, temp->priority);
        temp = temp->next;
    }
    printf("\n");
}


/*===============================================================================
SECTION 4 : DOUBLE ENDED QUEUE (DEQUE) USING ARRAY
===============================================================================*/

/*---------------- ALGORITHM ----------------
INSERT_FRONT(item), INSERT_REAR(item)
DELETE_FRONT(), DELETE_REAR()
---------------------------------------------*/

int deque[MAX];
int frontD = -1, rearD = -1;

void insertFront(int val) {
    if ((frontD == 0 && rearD == MAX - 1) || (frontD == rearD + 1)) {
        printf("Deque Overflow!\n");
        return;
    }
    if (frontD == -1)
        frontD = rearD = 0;
    else if (frontD == 0)
        frontD = MAX - 1;
    else
        frontD--;

    deque[frontD] = val;
}

void insertRear(int val) {
    if ((frontD == 0 && rearD == MAX - 1) || (frontD == rearD + 1)) {
        printf("Deque Overflow!\n");
        return;
    }
    if (frontD == -1)
        frontD = rearD = 0;
    else if (rearD == MAX - 1)
        rearD = 0;
    else
        rearD++;

    deque[rearD] = val;
}

void deleteFront() {
    if (frontD == -1) {
        printf("Deque Underflow!\n");
        return;
    }
    printf("Deleted from Front: %d\n", deque[frontD]);

    if (frontD == rearD)
        frontD = rearD = -1;
    else if (frontD == MAX - 1)
        frontD = 0;
    else
        frontD++;
}

void deleteRear() {
    if (frontD == -1) {
        printf("Deque Underflow!\n");
        return;
    }
    printf("Deleted from Rear: %d\n", deque[rearD]);

    if (frontD == rearD)
        frontD = rearD = -1;
    else if (rearD == 0)
        rearD = MAX - 1;
    else
        rearD--;
}

void displayDeque() {
    if (frontD == -1) {
        printf("Deque: Empty\n");
        return;
    }
    printf("Deque: ");
    int i = frontD;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rearD) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}


/*===============================================================================
MAIN FUNCTION — AUTO RUN ALL QUEUE OPERATIONS
===============================================================================*/
int main() {

    printf("\n==============================\n");
    printf("   ORDINARY QUEUE (LL)\n");
    printf("==============================\n");

    enqueueLL(10);
    enqueueLL(20);
    enqueueLL(30);
    displayLL();
    dequeueLL();
    displayLL();


    printf("\n==============================\n");
    printf("  CIRCULAR QUEUE (ARRAY)\n");
    printf("==============================\n");

    enqueueC(1);
    enqueueC(2);
    enqueueC(3);
    displayC();
    dequeueC();
    displayC();


    printf("\n==============================\n");
    printf(" PRIORITY QUEUE (LL)\n");
    printf("==============================\n");

    enqueuePriority(40, 2);
    enqueuePriority(10, 1);
    enqueuePriority(30, 3);
    displayPriority();
    dequeuePriority();
    displayPriority();


    printf("\n==============================\n");
    printf("        DEQUE (ARRAY)\n");
    printf("==============================\n");

    insertRear(10);
    insertRear(20);
    insertFront(5);
    displayDeque();
    deleteFront();
    deleteRear();
    displayDeque();

    return 0;
}
